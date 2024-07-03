// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WindmillDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYRMIDONPROTO_API UWindmillDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Length = 9.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Angle = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 0.0f;
};
