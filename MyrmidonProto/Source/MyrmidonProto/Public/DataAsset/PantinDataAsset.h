// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PantinDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYRMIDONPROTO_API UPantinDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General Settings")
	float GravityScale = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General Settings")
	float MaxAcceleration = 2048.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General Settings")
	float BrakingFrictionFactor = 2.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General Settings")
	float Mass = 100.0f;


	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Walking")
	float MaxStepHeight = 45.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Walking", meta = (ClampMin = "0.0", ClampMax = "90.0", UIMin = "0.0", UIMax = "90.0"))
	float WalkableFloorAngle = 44.7f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Walking")
	float GroundFriction = 8.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Walking")
	float MaxWalkSpeed = 500.0f;


	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping / Falling")
	float JumpZVelocity = 420.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping / Falling")
	float BrakingDecelerationFalling = 600.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping / Falling")
	float AirControl = 0.6f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping / Falling")
	float AirControlBoostMultiplier = 2.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping / Falling")
	float AirControlBoostVelocityThreshold = 25.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Jumping / Falling")
	float FallingLateralFriction = 0.0f;



	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float MaxGravity = 2.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float MinGravity = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float FunkyGravityDuration = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	float CoyoteTime = 0.1f;


	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	float WindPower = 10.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	int WindMaxHit = 3;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	float OppositInputsMult = 0.6f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	FVector WindDirection = FVector(1.0f, 0.0f, 0.0f);



	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Climb")
	float ClimbPantinHeight = 60.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Climb")
	float ClimbMinArea = 50.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Climb")
	float ClimbSpeed = 5.0f;
};
