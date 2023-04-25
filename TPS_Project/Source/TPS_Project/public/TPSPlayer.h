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
	//Field of View ����� ����ϱ� ���� �������Ʈ �б� ���
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	class UCameraComponent* tpsCamComp;
	
	// �̵� �ӵ�
	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float walkSpeed = 200;

	UPROPERTY(EditAnywhere, Category = PlayerSetting)
	float runSpeed = 600;

	UPROPERTY(VisibleAnywhere, Category = GunMesh)
	class USkeletalMeshComponent* gunMeshComp;

	UPROPERTY(EditDefaultsOnly, Category = BulletFactory)
	TSubclassOf<class ABullet> bulletFactory;

	UPROPERTY(VisibleAnywhere, Category = GunMesh)
	class UStaticMeshComponent* sniperGunComp;

	UPROPERTY(EditDefaultsOnly, Category= SniperUI)
	TSubclassOf<class UUserWidget> sniperUIFactory;

	// �Ѿ� ���� ȿ��
	UPROPERTY(EditAnywhere, Category = BulletEffect)
	class UParticleSystem* bulletEffectFactory;

	// �Ϲ� ���� UI
	UPROPERTY(EditDefaultsOnly, Category = SniperUI)
	TSubclassOf<class UUserWidget> crosshairUIFactory;

	UPROPERTY(EditDefaultsOnly, Category = CameraMotion)
	TSubclassOf<class UCameraShakeBase> cameraShake;

	UPROPERTY(EditDefaultsOnly, Category = Sound)
	class USoundBase* bulletSound;

	// ũ�ν���� �ν��Ͻ�
	class UUserWidget* _crosshairUI;

	// �޸��� �̺�Ʈ ó�� �Լ�
	void InputRun();

	// �������� UI ���� �ν��Ͻ�
	class UUserWidget* _sniperUI;

	// �̵� ����
	FVector direction;

	// ���� ��ź���� ����ϰ� �ִ���
	bool bUsingGrenadeGun = true;

	// �������� ���� ������
	bool bSniperAim = false;

	// �¿� ȸ��
	void Turn(float value);
	// ���� ȸ�� �Է� ó��
	void LookUp(float value);
	//�¿� �̵� �Լ�
	void InputHorizontal(float value);
	//���� �̵� �Լ�
	void InputVertical(float value);
	//����
	void InputJump();
	// �÷��̾� �̵� ó��
	void Move();
	// �Ѿ� �߻� ó�� �Լ�
	void InputFire();

	// ��ź������ ����
	void ChangeToGrenadeGun();

	// �������� ������ ����
	void ChangeToSniperGun();

	// �������� ����
	void SniperAim();

	// ���� ����
	void SniperRelease();
};
