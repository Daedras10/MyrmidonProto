// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerPantinAnimator.generated.h"

UENUM(Blueprintable)
enum EDirection : uint8
{
	Up,
	Down,
	Left,
	Right,
	UpRight,
	DownRight,
	UpLeft,
	DownLeft
};

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

	UFUNCTION(BlueprintCallable)
	void InputDirection(EDirection Direction);

	void AddInputDirectionPositive(EDirection Direction);
	void AddInputDirectionNegative(EDirection Direction);

	UFUNCTION(BlueprintCallable)
	EDirection NextDirection(const EDirection Current, const bool Positive);

	UFUNCTION(BlueprintCallable)
	void ClearDirections();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnCirclePositive();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnCircleNegative();

	

	

	TArray<EDirection> DirectionsPositive;
	TArray<EDirection> DirectionsNegative;
};
