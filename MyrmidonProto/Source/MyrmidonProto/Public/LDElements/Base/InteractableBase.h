// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "InteractableBase.generated.h"

UCLASS()
class MYRMIDONPROTO_API AInteractableBase : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsPickupable = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsInteractable = true;

	virtual bool IsInteractable_Implementation() override;
};
