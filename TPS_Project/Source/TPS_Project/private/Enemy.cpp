// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "EnemyFSM.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// ���̷�Ż �޽� ������ �ε�
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT(" / Script / Engine.SkeletalMesh'/Game/Enemy/Model/vampire_a_lusth.vampire_a_lusth'"));

	if (tempMesh.Succeeded()) {
		// ������ �Ҵ� �� �⺻ ����
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -88), FRotator(0, -90, 0));
		GetMesh()->SetRelativeScale3D(FVector(0.84f));
	}

	// ĸ�� ������Ʈ�� �ƴ� �޽ø� �������� ��Ʈ�� ä���� �����ؾ��Ѵ�. ��ݽ� Visibility�� �����ϵ��� ���������Ƿ� block���� �����ϴ� ��
	GetMesh()->SetCollisionProfileName(TEXT("Custom..."));
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	// ��(�÷��̾�)�� ������ �� �ڵ����� ������ �� ������ ���ϵ��� ����
	GetCharacterMovement()->bOrientRotationToMovement = true;

	fsm = CreateDefaultSubobject<UEnemyFSM>(TEXT("FSM"));

	// ��� �ڿ� _C�� �ٿ��� �������Ʈ Ŭ������ �ν��ؼ� ������ ���� �ʴ´�.
	ConstructorHelpers::FClassFinder<UAnimInstance> tempClass(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/ABP_Enemy.ABP_Enemy_C'"));
	if (tempClass.Succeeded()) {
		GetMesh()->SetAnimInstanceClass(tempClass.Class);
	}

	// ���忡 ��ġ�ǰų� ������ �� �ڵ�����
	// AIController�κ��� Possess �� �� �ֵ��� ����
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

