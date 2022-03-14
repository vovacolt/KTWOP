// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealBaseGitSetupGameModeBase.generated.h"

/**
 * 
 */
USTRUCT()
struct FMyStruct
{
	GENERATED_BODY()
	
	
};



UCLASS()
class UNREALBASEGITSETUP_API AUnrealBaseGitSetupGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	float data;
	
	UPROPERTY()
	AActor* actor;

	UFUNCTION(BlueprintCallable)
	float GGG(float& output, float input);
	
};
