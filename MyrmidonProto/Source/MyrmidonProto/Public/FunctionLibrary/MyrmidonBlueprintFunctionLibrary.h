// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyrmidonBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API UMyrmidonBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(Blueprintable, BlueprintPure, BlueprintCallable, Category = "Myrmidon")
	static float GetMinimalDistanceFromPointToRay(FVector Origin, FVector Forward, FVector Target);

	
	
};
