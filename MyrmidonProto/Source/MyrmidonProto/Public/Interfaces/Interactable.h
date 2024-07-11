// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 **/
class MYRMIDONPROTO_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartA();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartB();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EndA();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EndB();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ActiveA();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ActiveB();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PickUp();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Drop();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartHover();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EndHover();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHighlighted(bool bShouldHighlight);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	int GetCorkBoardIndex();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool IsPickable();
};
