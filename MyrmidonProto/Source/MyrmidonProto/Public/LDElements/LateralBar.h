// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LateralBar.generated.h"

class ULateralBarDataAsset;

UCLASS()
class MYRMIDONPROTO_API ALateralBar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALateralBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Angle = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Velocity = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Drag = 0.98f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InputForce = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ExitForce = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxVelocity = 10.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ULateralBarDataAsset* DataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldLerp = false;
};
