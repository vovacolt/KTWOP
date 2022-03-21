// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

#include "Components\SphereComponent.h"


// Sets default values
ABullet::ABullet()
{
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
	
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComponent = CreateDefaultSubobject<UBulletAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);


	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionComponent->InitSphereRadius(BulletSpeed);
	CollisionComponent->SetCollisionProfileName(TEXT("Pawn"));
	CollisionComponent->SetupAttachment(RootComponent);
	CollisionComponent->SetHiddenInGame(false);

	
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
	if ((TargetEnemy == nullptr) || (!IsValid(TargetEnemy)))
	{
		this->Destroy();
	}
	TargetEnemy->GetActorLocation();
	FVector newLocation = FMath::VInterpTo(
		TargetEnemy->GetActorLocation(),
		RootComponent->GetComponentLocation(),
		DeltaTime,
		BulletSpeed
		);
	RootComponent->SetWorldLocation(newLocation);
	
}

