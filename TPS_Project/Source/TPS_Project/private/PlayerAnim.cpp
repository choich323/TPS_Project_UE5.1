// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "TPSPlayer.h"

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	// 소유 폰 얻어 오기
	// 플레이어로 캐스팅
	// 이동 속도
	// 플레이어의 전방 벡터
	// speed에 값 할당
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto ownerPawn = TryGetPawnOwner();
	auto player = Cast<ATPSPlayer>(ownerPawn);
	// 캐스트에 성공했으면
	if (player) {
		FVector velocity = player->GetVelocity();
		FVector forwardvector = player->GetActorForwardVector();
		speed = FVector::DotProduct(forwardvector, velocity);
	}
}
