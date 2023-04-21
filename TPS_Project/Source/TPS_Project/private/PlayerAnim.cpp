// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "TPSPlayer.h"
#include <GameFramework/CharacterMovementComponent.h>

void UPlayerAnim::PlayAttackAnim()
{
	Montage_Play(attackAnimMontage);
}

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	// ���� �� ��� ����
	// �÷��̾�� ĳ����
	// �̵� �ӵ�
	// �÷��̾��� ���� ����
	// speed�� �� �Ҵ�
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto ownerPawn = TryGetPawnOwner();
	auto player = Cast<ATPSPlayer>(ownerPawn);
	// ĳ��Ʈ�� ����������
	if (player) {
		FVector velocity = player->GetVelocity();
		// ���� �ӵ� �Ҵ�
		FVector forwardvector = player->GetActorForwardVector();
		speed = FVector::DotProduct(forwardvector, velocity);
		// �¿� �ӵ� �Ҵ�
		FVector rightVector = player->GetActorRightVector();
		direction = FVector::DotProduct(rightVector, velocity);
		// �÷��̾ ���߿� �ִ��� Ȯ��
		auto movement = player->GetCharacterMovement();
		isInAir = movement->IsFalling();
	}
}
