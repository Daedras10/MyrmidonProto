// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/SwitchBase.h"
#include "GameFramework/Actor.h"
#include "DestroyingPlatform.generated.h"

class UDestroyingPlatformDataAsset;

UCLASS()
class MYRMIDONPROTO_API ADestroyingPlatform : public ASwitchBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestroyingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DisapearDelay = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RespawnDelay = 3.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector PlatformScale = FVector(1.0f, 1.0f, 0.2f);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDestroyingPlatformDataAsset* DataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;
};
