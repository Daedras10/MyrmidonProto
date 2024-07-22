// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/SwitchBase.h"
#include "GameFramework/Actor.h"
#include "GodRay.generated.h"

class UGodRayDataAsset;

UCLASS()
class MYRMIDONPROTO_API AGodRay : public ASwitchBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGodRay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Settings")
	void UpdateFromDataAsset();

	virtual void OnConstruction(const FTransform& Transform) override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGodRayDataAsset* DataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;


	/* Settings */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float FallingSpeed = 30.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float FallingMaxSpeed = -50.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float JumpPower = 250.0f;


	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	FVector RayWidthScale = FVector(2.0f, 2.0f, 4.0f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float RayAttraction = 3.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings")
	float SpotSpeed = 1000.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MaxHeight = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float InitialPosition = 0.5f;

};
