// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "Bullet.h"
#include <Blueprint/UserWidget.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ATPSPlayer::ATPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// ���̷�Ż �޽� ����
	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'"));
	if (TempMesh.Succeeded()) {
		GetMesh()->SetSkeletalMesh(TempMesh.Object);
		// FRotator: Pitch - Y, Yaw - Z, Roll - X
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
	}

	// TPS ī�޶� �� ���̱�
	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	springArmComp->SetupAttachment(RootComponent);
	// �÷��̾� ���� ī�޶��� ��ġ
	springArmComp->SetRelativeLocation(FVector(0, 70, 90));
	// Ÿ�ٰ� ī�޶� ���̿� �浹�� ���� ��� Ÿ�ٰ��� ���� �Ÿ� ����
	springArmComp->TargetArmLength = 400;
	// �÷��̾ ȸ���ϸ� �÷��̾ ������ ������ �ϵ� ȸ��
	springArmComp->bUsePawnControlRotation = true;

	tpsCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TpsCamComp"));
	tpsCamComp->SetupAttachment(springArmComp);
	// �÷��̾ ȸ���ϰ� ���������� ȸ���� �� ī�޶� ���������� ������ ȸ������ �ʰ� �׳� ������ ���� ����
	tpsCamComp->bUsePawnControlRotation = false;
	// �÷��̾��� ȸ�� ���
	bUseControllerRotationYaw = true;
	// �ִ� ���� Ƚ��
	JumpMaxCount = 2;

	// ���̷�Ż�޽� ������Ʈ ���
	gunMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMeshComp"));
	// �θ� ������Ʈ�� mesh������Ʈ�� ����
	gunMeshComp->SetupAttachment(GetMesh());
	// ���̷�Ż�޽� ������ �ε�
	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempGunMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/FPWeapon/Mesh/SK_FPGun.SK_FPGun'"));
	if (TempGunMesh.Succeeded()) {
		gunMeshComp->SetSkeletalMesh(TempGunMesh.Object);
		gunMeshComp->SetRelativeLocation(FVector(-14, 52, 120));
	}
	
	// �������� ������Ʈ ���
	sniperGunComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SniperGunComp"));
	sniperGunComp->SetupAttachment(GetMesh());
	// �޽� ������ �ε�
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempSniperMesh(TEXT("/Script/Engine.StaticMesh'/Game/SniperGun/sniper1.sniper1'"));
	if (TempSniperMesh.Succeeded()) {
		// �޽� �Ҵ�, ��ġ, ũ�� ����
		sniperGunComp->SetStaticMesh(TempSniperMesh.Object);
		sniperGunComp->SetRelativeLocation(FVector(-22, 55, 120));
		sniperGunComp->SetRelativeScale3D(FVector(0.15f));
	}

}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();
	// �������� UI ���� �ν��Ͻ� ����
	_sniperUI = CreateWidget(GetWorld(), sniperUIFactory);
	// �Ϲ� ���� UI �ν��Ͻ� ����
	_crosshairUI = CreateWidget(GetWorld(), crosshairUIFactory);
	// UI���(�⺻ �����̹Ƿ�)
	_crosshairUI->AddToViewport();

	// �⺻���� �������� �� ����ϵ���
	ChangeToSniperGun();
}

// Called every frame
void ATPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Move();
}

// Called to bind functionality to input
void ATPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// �þ� ����
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATPSPlayer::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATPSPlayer::LookUp);
	// ��ġ ����
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ATPSPlayer::InputHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ATPSPlayer::InputVertical);
	// ����
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ATPSPlayer::InputJump);
	// ���
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATPSPlayer::InputFire);
	// �� ���� ����
	PlayerInputComponent->BindAction(TEXT("Grenade Gun"), IE_Pressed, this, &ATPSPlayer::ChangeToGrenadeGun);
	PlayerInputComponent->BindAction(TEXT("Sniper Gun"), IE_Pressed, this, &ATPSPlayer::ChangeToSniperGun);
	// �������� ����
	PlayerInputComponent->BindAction(TEXT("SniperMode"), IE_Pressed, this, &ATPSPlayer::SniperAim);
	PlayerInputComponent->BindAction(TEXT("SniperMode"), IE_Released, this, &ATPSPlayer::SniperAim);
}

void ATPSPlayer::Turn(float value)
{
	AddControllerYawInput(value);
}

void ATPSPlayer::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void ATPSPlayer::InputHorizontal(float value)
{
	// �𸮾� ����Ʈ������ �¿찡 Y��
	direction.Y = value;
}

void ATPSPlayer::InputVertical(float value)
{
	// �𸮾� ����Ʈ������ ���İ� X��
	direction.X = value;
}

void ATPSPlayer::InputJump()
{
	Jump();
}

void ATPSPlayer::Move()
{
	// ���� ��ǥ�� ��� ��ǥ�� �ٲٱ� ���� TransformVector �Լ��� ���.
	// TransformVector�Լ��� Ư���� ���͸� �ڽ��� �������� ��ȯ�����ش�.
	direction = FTransform(GetControlRotation()).TransformVector(direction);
	//SetActorLocation(GetActorLocation() + direction * walkSpeed * DeltaTime);
	// ���� ����� �ᵵ ������, CharacterMovement ������Ʈ�� ����ִ� �Լ��� ����ϴ� ���� �� ���ϴ�.
	// �ش� ������Ʈ�� ���⸸ �־��ָ� �˾Ƽ� ����ؼ� ĳ���Ͱ� �̵��Ѵ�. ���� ���� ������ ����
	AddMovementInput(direction);
	direction = FVector::ZeroVector;
}

void ATPSPlayer::InputFire()
{
	// ��ź�� ���� ���̸�
	if (bUsingGrenadeGun) {
		FTransform firePosition = gunMeshComp->GetSocketTransform(TEXT("FirePosition"));
		GetWorld()->SpawnActor<ABullet>(bulletFactory, firePosition);
	}
	// �������� �� ���� ���̸�
	else {
		// LineTrace�� ���� ��ġ
		FVector startPos = tpsCamComp->GetComponentLocation();
		// LineTrace�� ���� ��ġ
		FVector endPos = tpsCamComp->GetComponentLocation() + tpsCamComp->GetForwardVector() * 5000;
		// LineTrace�� �浹 ������ ���� ����
		FHitResult hitInfo;
		// �浹 �ɼ� ���� ����
		FCollisionQueryParams params;
		// �ڱ� �ڽ�(�÷��̾�)�� �浹���� ����
		params.AddIgnoredActor(this);
		// Channel ���͸� �̿��� LineTrace �浹 ����
		bool bHit = GetWorld()->LineTraceSingleByChannel(hitInfo, startPos, endPos, ECC_Visibility, params);
		// �浹���� �� > �� ��ġ�� ȿ���� �߻����Ѿ� ��
		if (bHit) {
			// �ε��� ��ġ
			FTransform bulletTrans;
			// ��ġ �Ҵ�
			bulletTrans.SetLocation(hitInfo.ImpactPoint);
			// �Ѿ� ���� ȿ�� �ν��Ͻ� ����(���忡 ����Ʈ�� transformation�� ����)
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), bulletEffectFactory, bulletTrans);
			
			// �ε��� ��ü�� ������Ʈ
			auto hitComp = hitInfo.GetComponent();
			// ������Ʈ�� ���� ó���� �Ǿ� ������
			if (hitComp && hitComp->IsSimulatingPhysics()) {
				// �ε��� ������ ���� ��� ���͸� Ȱ��, ��ü�� ���Կ� �°� ����.
				FVector force = -1 * hitInfo.ImpactNormal * hitComp->GetMass() * 500000;
				hitComp->AddForce(force);
			}
		}
	}
}

void ATPSPlayer::ChangeToGrenadeGun()
{
	bUsingGrenadeGun = true;
	sniperGunComp->SetVisibility(false);
	gunMeshComp->SetVisibility(true);
}

void ATPSPlayer::ChangeToSniperGun()
{
	bUsingGrenadeGun = false;
	sniperGunComp->SetVisibility(true);
	gunMeshComp->SetVisibility(false);
}

void ATPSPlayer::SniperAim()
{
	if (bUsingGrenadeGun)
		return;
	if (!bSniperAim) {
		// ���� ������ ����, ����Ʈ�� ���, �þ߰� ����
		bSniperAim = true;
		_crosshairUI->RemoveFromViewport();
		_sniperUI->AddToViewport();
		tpsCamComp->SetFieldOfView(45.0f);
	}
	else {
		bSniperAim = false;
		_sniperUI->RemoveFromViewport();
		_crosshairUI->AddToViewport();
		tpsCamComp->SetFieldOfView(90.0f);
	}
}
