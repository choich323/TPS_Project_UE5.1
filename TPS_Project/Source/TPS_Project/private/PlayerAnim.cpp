// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "TPSPlayer.h"

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
		FVector forwardvector = player->GetActorForwardVector();
		speed = FVector::DotProduct(forwardvector, velocity);
	}
}
