// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework\Actor.h"
#include "TurretSystem\AbilitySystems\BulletAbilitySystemComponent.h"
#include "Bullet.generated.h"

class USphereComponent;
UCLASS()
class TURRETSYSTEM_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

	UPROPERTY()
	AActor* TargetEnemy;
	
	float BulletSpeed = 1;

	UPROPERTY(BlueprintReadOnly)
	UBulletAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	USphereComponent* CollisionComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
