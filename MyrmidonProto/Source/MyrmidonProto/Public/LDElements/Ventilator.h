// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/SwitchBase.h"
#include "GameFramework/Actor.h"
#include "Interfaces/VisualSwitcher.h"
#include "Interfaces/WindIgnored.h"
#include "Ventilator.generated.h"

UCLASS()
class MYRMIDONPROTO_API AVentilator : public ASwitchBase, public IWindIgnored 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVentilator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WindPower = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector WindDirection = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector WindBoxScale = FVector(1.0f, 1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector WindBoxOffset = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float VentilatorHeightMult = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Activated = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RotationSpeed = 1.0f;

};
