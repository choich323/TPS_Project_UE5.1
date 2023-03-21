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
	
	// 월드에서 타겟(플레이어) 가져오기
	auto actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATPSPlayer::StaticClass());
	// 플레이어 클래스 형변환
	target = Cast<ATPSPlayer>(actor);
	// 소유 객체 가져오기
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
	// 일정 시간 대기 후 이동 상태로 전환
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > idleDelayTime) {
		mState = EEnemyState::Move;
		currentTime = 0;
	}
}

void UEnemyFSM::MoveState()
{
	// 목적지(타깃;플레이어 위치)
	FVector destination = target->GetActorLocation();
	// 현재 내 위치(적의 위치)
	FVector dir = destination - me->GetActorLocation();
	// 벡터를 정규화해서 값으로 넘겨주기
	me->AddMovementInput(dir.GetSafeNormal());
	
	// 가까워지면 공격 상태로 전환
	if (dir.Size() < attackRange) {
		mState = EEnemyState::Attack;
	}
}

void UEnemyFSM::AttackState()
{
	// 시간이 흐르면
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > attackDelayTime) {
		PRINT_LOG(TEXT("Attack"));
		currentTime = 0;
	}
	// 거리 계산
	float distance = FVector::Distance(target->GetActorLocation(), me->GetActorLocation());
	// 거리가 멀어지면 이동 상태로 전환
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
	// 등속으로 하강
	me->SetActorLocation(me->GetActorLocation() + dieSpeed * FVector::DownVector * GetWorld()->DeltaTimeSeconds);

	// 2미터 이상 아래로 내려가면 제거
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
		// 캡슐 충돌체 비활성화
		me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

