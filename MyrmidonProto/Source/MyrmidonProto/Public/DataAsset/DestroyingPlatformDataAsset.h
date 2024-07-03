// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DestroyingPlatformDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYRMIDONPROTO_API UDestroyingPlatformDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DisapearDelay = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RespawnDelay = 3.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector PlatformScale = FVector(1.0f, 1.0f, 0.2f);
};
