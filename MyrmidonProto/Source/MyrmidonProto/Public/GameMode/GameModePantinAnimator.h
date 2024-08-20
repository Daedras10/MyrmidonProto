// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModePantinAnimator.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API AGameModePantinAnimator : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RecordTimer;

	//TODO Camera
	//TODO Sequences

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool WindIsActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector WindDirection;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName AnimatorTag = "Animator";

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName PantinTag = "Pantin";
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool PantinEndOfGame;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool AnimatorEndOfGame;


protected:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanEndGame();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
	bool IsPlayerPresent(bool IsPantin);
};
