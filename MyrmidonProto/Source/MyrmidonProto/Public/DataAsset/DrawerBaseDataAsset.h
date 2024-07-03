// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DrawerBaseDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API UDrawerBaseDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float Speed = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float MinimalPercentDistance = 0.002f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	bool ModeFollowMouse = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float DelayBeforeMovement = 0.5f;
	
};
