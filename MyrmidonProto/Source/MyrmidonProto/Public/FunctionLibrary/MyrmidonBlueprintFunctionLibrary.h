// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyrmidonBlueprintFunctionLibrary.generated.h"

USTRUCT(Blueprintable)
struct FDistanceData
{
	GENERATED_BODY()

public:
	FDistanceData()
	{
		Distance = 0;
		Angle = 0;
	}
	
	FDistanceData(const float Distance, const float Angle)
	{
		this->Distance = Distance;
		this->Angle = Angle;
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DistanceData")
	float Distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DistanceData")
	float Angle;
};


/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API UMyrmidonBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(Blueprintable, BlueprintPure, BlueprintCallable, Category = "Myrmidon")
	static FDistanceData GetMinimalDistanceFromPointToRay(FVector Origin, FVector Forward, FVector Target);

	
	UFUNCTION(Blueprintable, BlueprintPure, BlueprintCallable, Category = "Myrmidon")
	static bool IsDistanceDataValid(FDistanceData Data, float MaxDistance, float MaxAngle);

	
	
};
