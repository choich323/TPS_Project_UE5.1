// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include <Components/SphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 충돌체 등록
	collisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	// 콜리전 설정
	collisionComp->SetCollisionProfileName(TEXT("BlockAll"));
	// 콜리전 크기 설정
	collisionComp->SetSphereRadius(13);
	// 루트로 설정
	RootComponent = collisionComp;

	// 외관 컴포넌트
	bodyMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMeshComp"));
	// 부모 컴포넌트 지정
	bodyMeshComp->SetupAttachment(collisionComp);
	// 충돌 비활성화
	bodyMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	// 외관 크기 설정
	bodyMeshComp->SetRelativeScale3D(FVector(0.25f));
	bodyMeshComp->SetRelativeLocation(FVector(0, 0, -12.5f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (TempMesh.Succeeded()) {
		bodyMeshComp->SetStaticMesh(TempMesh.Object);
	}

	// 발사체 컴포넌트
	movementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComp"));
	// movement 컴포넌트가 갱신시킬 컴포넌트 지정: 콜리전이 업데이트되어야 함
	movementComp->SetUpdatedComponent(collisionComp);
	// 초기 속도
	movementComp->InitialSpeed = 5000;
	// 최대 속도
	movementComp->MaxSpeed = 5000;
	// 반동 여부
	movementComp->bShouldBounce = true;
	// 반동 값
	movementComp->Bounciness = 0.3f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

