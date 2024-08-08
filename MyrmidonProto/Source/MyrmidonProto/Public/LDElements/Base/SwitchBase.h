// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "Interfaces/VisualSwitcher.h"
#include "SwitchBase.generated.h"

UCLASS()
class MYRMIDONPROTO_API ASwitchBase : public AInteractableBase, public IVisualSwitcher
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitchBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsPantinView = false;

};
