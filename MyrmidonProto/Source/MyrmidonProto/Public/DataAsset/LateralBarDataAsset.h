// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LateralBarDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYRMIDONPROTO_API ULateralBarDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Angle = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Velocity = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Drag = 0.98f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InputForce = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ExitForce = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxVelocity = 10.0f;
};
