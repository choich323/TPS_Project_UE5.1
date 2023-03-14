// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSPlayer.generated.h"

UCLASS()
class TPS_PROJECT_API ATPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	
	UPROPERTY(VisibleAnywhere, Category=Camera)
	class USpringArmComponent* springArmComp;

	UPROPERTY(VisibleAnywhere, Category=Camera)
	class UCameraComponent* tpsCamComp;
	
	// 이동 속도
	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float walkSpeed = 600;
	// 이동 방향
	FVector direction;

	// 좌우 회전
	void Turn(float value);
	// 상하 회전 입력 처리
	void LookUp(float value);
	//좌우 이동 함수
	void InputHorizontal(float value);
	//전후 이동 함수
	void InputVertical(float value);
	//점프
	void InputJump();
	// 플레이어 이동 처리
	void Move();
};
