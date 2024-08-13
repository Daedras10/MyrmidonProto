// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PantinAnimatorPlayerState.generated.h"

class UWorldDataAsset;
/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API APantinAnimatorPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	bool IsPantin = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	int PantinCheckPointIndex = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWorldDataAsset* WorldDataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int> PantinCheckPointIndexes;
	
	

	void BeginPlay() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable)
	void SkipToNextCheckpoint();
	
	UFUNCTION(BlueprintCallable)
	void SkipToPreviousCheckpoint();
	
	
	
};
