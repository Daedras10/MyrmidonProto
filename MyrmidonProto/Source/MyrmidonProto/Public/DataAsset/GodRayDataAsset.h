// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GodRayDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API UGodRayDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pantin settings")
	float FallingSpeed = 30.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pantin settings")
	float FallingMaxSpeed = -50.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pantin settings")
	float JumpPower = 250.0f;



	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ray settings")
	float RayAttraction = 3.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ray settings")
	float SpotSpeed = 1000.0f;

	// UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ray settings")
	// FVector RayWidthScale = FVector(2.0f, 2.0f, 4.0f);

	// UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ray settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	// float MaxHeight = 1.0f;
	//
	// UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ray settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	// float InitialPosition = 0.5f;
};
