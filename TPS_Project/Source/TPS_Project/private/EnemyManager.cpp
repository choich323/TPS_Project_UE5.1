// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Enemy.h"
#include <EngineUtils.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// ƽ �Լ��� �� �����Ӹ��� ������� �ʵ��� ����(�⺻ ���� true)
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
	// ���� �ð� ����
	float createTime = FMath::RandRange(minTime, maxTime);

	// �̷� ����� Tick ��ĺ��� �� ���� ����.
	// Ÿ�̸� �Ŵ����� �˸� ���(�ð�� �˸� �ð��� �Ѱܼ� ������ Ÿ�ֿ̹� �˸��� �޴� ���)
	// (�˸� �ð�, �˸� ���� ��ü(�ڱ� �ڽ�), �˸� ���� �Լ�, �˸� �ð�)

	FindSpawnPoints();

	GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle, this, &AEnemyManager::CreateEnemy, createTime);
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyManager::CreateEnemy()
{
	// ���� ��ġ
	int index = FMath::RandRange(0, spawnPoints.Num() - 1);
	// �� ���� �� ��ġ
	GetWorld()->SpawnActor<AEnemy>(enemyFactory, spawnPoints[index]->GetActorLocation(), FRotator(0));

	// �ٽ� Ÿ�̸� ����
	float createTime = FMath::RandRange(minTime, maxTime);
	GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle, this, &AEnemyManager::CreateEnemy, createTime);
}

void AEnemyManager::FindSpawnPoints()
{
	/*
	// ������ ���͸���
	for (TActorIterator<AActor> it(GetWorld()); it; ++it) {
		AActor* spawn = *it;
		// ������ �̸��� ���ϴ� ������ �� ������ �߰�
		if (spawn->GetName().Contains(TEXT("BP_EnemySpawnPoint"))) {
			spawnPoints.Add(spawn);
		}
	}*/

	// �迭�� ����� ��� ���� ��ü�� �迭�� �־ �˻縦 ������ ���
	TArray<AActor*> allActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), allActors);
	for (auto spawn : allActors) {
		if (spawn->GetName().Contains(TEXT("BP_EnemySpawnPoint"))) {
			spawnPoints.Add(spawn);
		}
	}
}

