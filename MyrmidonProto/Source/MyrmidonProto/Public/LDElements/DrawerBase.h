// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/InteractableBase.h"
#include "GameFramework/Actor.h"
#include "Interfaces/VisualSwitcher.h"
#include "DrawerBase.generated.h"

class UDrawerBaseDataAsset;

UCLASS()
class MYRMIDONPROTO_API ADrawerBase : public AInteractableBase, public IVisualSwitcher
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrawerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 1.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinimalPercentDistance = 0.002f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ModeFollowMouse = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DelayBeforeMovement = 0.5f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool StartClosed = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector DrawerScale = FVector(1.0f, 1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector HandleScale = FVector(0.05f, 0.05f, 0.3f);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDrawerBaseDataAsset* DataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;

};
