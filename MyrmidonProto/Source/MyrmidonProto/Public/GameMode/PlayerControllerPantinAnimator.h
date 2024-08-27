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
	
	void InputsToCirclePositive(FVector2D Inputs);
	void InputsToCircleNegative(FVector2D Inputs);

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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CirclePositiveProgression(float Progression);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CirclePositiveCancelled(float Progression);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CircleNegativeProgression(float Progression);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CircleNegativeCancelled(float Progression);

	
	
	TArray<EDirection> DirectionsPositive;
	TArray<EDirection> DirectionsNegative;

	UPROPERTY(BlueprintReadWrite)
	float CircleThreshold = 0.95f;

	UPROPERTY(BlueprintReadWrite)
	float AngleKindness = 0; //15.0f;

	UPROPERTY(BlueprintReadWrite)
	float CircleNotInteractingMaxTime = 0.5f;

	// UPROPERTY(BlueprintReadWrite)
	// float CircleNotInteractingTime = 0.0f; // Time since last input

	UPROPERTY(BlueprintReadWrite)
	float CircleStartAngle = -1.0f;

	UPROPERTY(BlueprintReadWrite)
	float ProgressionAllowed = 0.15f;

	UPROPERTY(BlueprintReadWrite)
	float CurrentProgressionPositive = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	float CurrentProgressionNegative = 0.0f;


private:
	void CancelCircle();
	
	FTimerHandle CircleInputTimeoutHandle;

	bool CircleDebug = false;
	float MinPercentChange = 0.01f;
};
