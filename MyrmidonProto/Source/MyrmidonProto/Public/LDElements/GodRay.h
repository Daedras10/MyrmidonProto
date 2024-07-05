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
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGodRayDataAsset* DataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;

};
