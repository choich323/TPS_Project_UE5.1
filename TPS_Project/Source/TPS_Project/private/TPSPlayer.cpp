// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
ATPSPlayer::ATPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// 스켈레탈 메시 설정
	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'"));
	if (TempMesh.Succeeded()) {
		GetMesh()->SetSkeletalMesh(TempMesh.Object);
		// FRotator: Pitch - Y, Yaw - Z, Roll - X
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
	}

	// TPS 카메라 암 붙이기
	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	springArmComp->SetupAttachment(RootComponent);
	// 플레이어 기준 카메라의 위치
	springArmComp->SetRelativeLocation(FVector(0, 70, 90));
	// 타겟과 카메라 사이에 충돌이 없을 경우 타겟과의 지정 거리 설정
	springArmComp->TargetArmLength = 400;
	// 플레이어가 회전하면 플레이어를 축으로 스프링 암도 회전
	springArmComp->bUsePawnControlRotation = true;

	tpsCamComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TpsCamComp"));
	tpsCamComp->SetupAttachment(springArmComp);
	// 플레이어가 회전하고 스프링암이 회전할 때 카메라가 스프링암을 축으로 회전하지 않고 그냥 스프링 암을 따라감
	tpsCamComp->bUsePawnControlRotation = false;
	// 플레이어의 회전 허용
	bUseControllerRotationYaw = true;
	// 최대 점프 횟수
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
	// 언리얼 뷰포트에서는 좌우가 Y축
	direction.Y = value;
}

void ATPSPlayer::InputVertical(float value)
{
	// 언리얼 뷰포트에서는 전후가 X축
	direction.X = value;
}

void ATPSPlayer::InputJump()
{
	Jump();
}

void ATPSPlayer::Move()
{
	// 절대 좌표를 상대 좌표로 바꾸기 위해 TransformVector 함수를 사용.
	// TransformVector함수는 특정한 벡터를 자신의 기준으로 변환시켜준다.
	direction = FTransform(GetControlRotation()).TransformVector(direction);
	//SetActorLocation(GetActorLocation() + direction * walkSpeed * DeltaTime);
	// 위의 방식을 써도 되지만, CharacterMovement 컴포넌트에 들어있는 함수를 사용하는 것이 더 편리하다.
	// 해당 컴포넌트에 방향만 넣어주면 알아서 계산해서 캐릭터가 이동한다. 점프 역시 동일한 원리
	AddMovementInput(direction);
	direction = FVector::ZeroVector;
}

