// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

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
}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();
	
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

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATPSPlayer::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATPSPlayer::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &ATPSPlayer::InputHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &ATPSPlayer::InputVertical);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ATPSPlayer::InputJump);
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

