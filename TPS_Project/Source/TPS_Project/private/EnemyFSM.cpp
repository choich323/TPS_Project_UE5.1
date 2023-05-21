// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFSM.h"
#include "TPSPlayer.h"
#include "Enemy.h"
#include <Kismet/GameplayStatics.h>
#include "TPS_Project.h"
#include <Components/CapsuleComponent.h>
#include "EnemyAnim.h"
#include <AIController.h>
#include <NavigationSystem.h>

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

	// ���� ��ü ��������: �� Ŭ������ ������ �ִ� ��ü(enemy)
	me = Cast<AEnemy>(GetOwner());

	// UEnemyAnim* �Ҵ�
	anim = Cast<UEnemyAnim>(me->GetMesh()->GetAnimInstance());

	// AAIController �Ҵ�
	ai = Cast<AAIController>(me->GetController());
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

// ����� ã�� ���� ��� ���� ��ġ�� ��Ʈ�� �ϵ��� ���� ��ġ �������� �Լ�
bool UEnemyFSM::GetRandomPositionInNavMesh(FVector centerLocation, float radius, FVector& dest)
{
	auto ns = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	FNavLocation loc;
	// �������� ����� true, �ƴϸ� false
	bool result = ns->GetRandomReachablePointInRadius(centerLocation, radius, loc);
	dest = loc.Location;
	return result;
}

void UEnemyFSM::IdleState()
{
	// ���� �ð� ��� �� �̵� ���·� ��ȯ
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > idleDelayTime) {
		mState = EEnemyState::Move;
		currentTime = 0;
		
		// ���� ��ġ ���ϱ�
		GetRandomPositionInNavMesh(me->GetActorLocation(), 500, randomPos);

		// �ִϸ��̼� ���� ����ȭ
		anim->animState = mState;
	}
}

void UEnemyFSM::MoveState()
{
	// ������(Ÿ��;�÷��̾� ��ġ)
	FVector destination = target->GetActorLocation();
	// ���� �� ��ġ(���� ��ġ)
	FVector dir = destination - me->GetActorLocation();
	// �Ʒ� �ڵ带 ���� ������ ���� ��ġ �̵��� �ȵȴ�
	//me->AddMovementInput(dir.GetSafeNormal());

	// NavigateSystem ��ü ������
	auto ns = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	// ������ �� ã�� ��� ������ �˻�
	FPathFindingQuery query;
	FAIMoveRequest req;
	
	// ���������� ������ �� �ִ� ����
	req.SetAcceptanceRadius(3); // ���������� 3cm �ٹ��̸� �̵� �������� �Ǵ�
	req.SetGoalLocation(destination); // �÷��̾ ã�´�

	// �� ã�⸦ ���� ���� ����
	ai->BuildPathfindingQuery(req, query);
	// �� ã�� ��� ��������
	FPathFindingResult r = ns->FindPathSync(query);

	// �� ã�⿡ �������� ���(�÷��̾ �ִ� ���)
	if (r.Result == ENavigationQueryResult::Success) {
		ai->MoveToLocation(destination);
	}
	// ������ ���
	else {
		// ���� ��ġ�� �̵�
		auto result = ai->MoveToLocation(randomPos);
		// �����ϸ�
		if (result == EPathFollowingRequestResult::AlreadyAtGoal) {
			// å�� ���ο� ��ġ�� �Ҵ����ֶ�� �Ǿ������� ��Ʈ�� ������ ���� ���� ��� ���·� ��ȯ
			mState = EEnemyState::Idle;
			currentTime = 0;
			anim->animState = mState;
		}
	}

	// ��������� ���� ���·� ��ȯ
	if (dir.Size() < attackRange) {
		// �� ã�� ��� ����
		ai->StopMovement();

		mState = EEnemyState::Attack;

		anim->animState = mState;
		anim->bAttackPlay = true;

		// ���� ���� ��ȯ �� ��� �ð��� �ٷ� �������� ó��
		currentTime = attackDelayTime;
	}
}

void UEnemyFSM::AttackState()
{
	// �ð��� �帣��
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > attackDelayTime) {
		// ����
		currentTime = 0;
		anim->bAttackPlay = true;
	}
	// �Ÿ� ���
	float distance = FVector::Distance(target->GetActorLocation(), me->GetActorLocation());
	// �Ÿ��� �־����� �̵� ���·� ��ȯ
	if (distance > attackRange) {
		mState = EEnemyState::Move;

		anim->animState = mState;

		GetRandomPositionInNavMesh(me->GetActorLocation(), 500, randomPos);
	}
}

void UEnemyFSM::DamageState()
{
	currentTime += GetWorld()->DeltaTimeSeconds;
	if (currentTime > damageDelayTime) {
		mState = EEnemyState::Idle;
		currentTime = 0.2f;

		anim->animState = mState;
	}
}

void UEnemyFSM::DieState()
{
	// ���� ���� �ִϸ��̼��� �� ������� �ʾҴٸ�
	if (anim->bDieDone == false) {
		return;
	}

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
	ai->StopMovement();
	if (hp > 0) {
		mState = EEnemyState::Damage;

		currentTime = 0;

		// �ǰ� �ִϸ��̼� ���
		// ��Ÿ�� ���� 2�� �� �ϳ��� �������� ���
		int32 index = FMath::RandRange(0, 1);
		FString sectionName = FString::Printf(TEXT("Damage%d"), index);
		anim->PlayDamageAnim(FName(*sectionName)); // ��Ʈ���� ����ȯ�ؼ� ����
	}
	else {
		mState = EEnemyState::Die;
		// ĸ�� �浹ü ��Ȱ��ȭ
		me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		// ���� �ִϸ��̼� ���(������ �̸��� �Ű������� �ִ´�)
		anim->PlayDamageAnim(TEXT("Die"));
	}
	// �ִϸ��̼� ���� ����ȭ
	anim->animState = mState;
}

