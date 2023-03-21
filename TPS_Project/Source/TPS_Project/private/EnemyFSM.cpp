// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFSM.h"
#include "TPSPlayer.h"
#include "Enemy.h"
#include <Kismet/GameplayStatics.h>
#include "TPS_Project.h"
#include <Components/CapsuleComponent.h>

// Sets default values for this component's properties
UEnemyFSM::UEnemyFSM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyFSM::BeginPlay()
{
	Super::BeginPlay();
	
	// ���忡�� Ÿ��(�÷��̾�) ��������
	auto actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATPSPlayer::StaticClass());
	// �÷��̾� Ŭ���� ����ȯ
	target = Cast<ATPSPlayer>(actor);
	// ���� ��ü ��������
	me = Cast<AEnemy>(GetOwner());
}


// Called every frame
void UEnemyFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (mState) {
	case EEnemyState::Idle:
		IdleState();
		break;
	case EEnemyState::Move:
		MoveState();
		break;
	case EEnemyState::Attack:
		AttackState();
		break;
	case EEnemyState::Damage:
		DamageState();
		break;
	case EEnemyState::Die:
		DieState();
		break;
	}
}

void UEnemyFSM::IdleState()
{
	// ���� �ð� ��� �� �̵� ���·� ��ȯ
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > idleDelayTime) {
		mState = EEnemyState::Move;
		currentTime = 0;
	}
}

void UEnemyFSM::MoveState()
{
	// ������(Ÿ��;�÷��̾� ��ġ)
	FVector destination = target->GetActorLocation();
	// ���� �� ��ġ(���� ��ġ)
	FVector dir = destination - me->GetActorLocation();
	// ���͸� ����ȭ�ؼ� ������ �Ѱ��ֱ�
	me->AddMovementInput(dir.GetSafeNormal());
	
	// ��������� ���� ���·� ��ȯ
	if (dir.Size() < attackRange) {
		mState = EEnemyState::Attack;
	}
}

void UEnemyFSM::AttackState()
{
	// �ð��� �帣��
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > attackDelayTime) {
		PRINT_LOG(TEXT("Attack"));
		currentTime = 0;
	}
	// �Ÿ� ���
	float distance = FVector::Distance(target->GetActorLocation(), me->GetActorLocation());
	// �Ÿ��� �־����� �̵� ���·� ��ȯ
	if (distance > attackRange) {
		mState = EEnemyState::Move;
	}
}

void UEnemyFSM::DamageState()
{
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > damageDelayTime) {
		mState = EEnemyState::Idle;
		currentTime = 0;
	}
}

void UEnemyFSM::DieState()
{
	// ������� �ϰ�
	me->SetActorLocation(me->GetActorLocation() + dieSpeed * FVector::DownVector * GetWorld()->DeltaTimeSeconds);

	// 2���� �̻� �Ʒ��� �������� ����
	if (me->GetActorLocation().Z < -200.0f) {
		me->Destroy();
	}
}

void UEnemyFSM::OnDamageProcess()
{
	hp--;
	if (hp > 0) {
		mState = EEnemyState::Damage;
	}
	else {
		mState = EEnemyState::Die;
		// ĸ�� �浹ü ��Ȱ��ȭ
		me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

