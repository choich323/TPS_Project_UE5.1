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
	//Field of View 기능을 사용하기 위해 블루프린트 읽기 허용
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	class UCameraComponent* tpsCamComp;
	
	// 이동 속도
	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float walkSpeed = 600;

	UPROPERTY(VisibleAnywhere, Category = GunMesh)
	class USkeletalMeshComponent* gunMeshComp;

	UPROPERTY(EditDefaultsOnly, Category = BulletFactory)
	TSubclassOf<class ABullet> bulletFactory;

	UPROPERTY(VisibleAnywhere, Category = GunMesh)
	class UStaticMeshComponent* sniperGunComp;

	UPROPERTY(EditDefaultsOnly, Category= SniperUI)
	TSubclassOf<class UUserWidget> sniperUIFactory;

	class UUserWidget* _sniperUI;

	// 이동 방향
	FVector direction;

	// 현재 유탄총을 사용하고 있는지
	bool bUsingGrenadeGun = true;

	// 스나이퍼 조준 중인지
	bool bSniperAim = false;

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
	// 총알 발사 처리 함수
	void InputFire();

	// 유탄총으로 변경
	void ChangeToGrenadeGun();

	// 스나이퍼 총으로 변경
	void ChangeToSniperGun();

	// 스나이퍼 조준
	void SniperAim();
};
