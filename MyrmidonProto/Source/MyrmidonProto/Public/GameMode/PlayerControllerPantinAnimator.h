// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerPantinAnimator.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API APlayerControllerPantinAnimator : public APlayerController
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
	void ConvertInputs(FVector2D Inputs);
	
};
