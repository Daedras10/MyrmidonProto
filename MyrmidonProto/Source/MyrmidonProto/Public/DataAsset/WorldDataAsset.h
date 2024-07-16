// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/SoftWorldReference.h"
#include "WorldDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API UWorldDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General Settings")
	FSoftWorldReference WorldReference;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General Settings")
	bool DebugSoloPlayerIsPantin = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General Settings")
	int DebugCurrentCheckpointIndex = 0;
	
};
