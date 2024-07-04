// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VisualSwitcher.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UVisualSwitcher : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYRMIDONPROTO_API IVisualSwitcher
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Switch(bool bToPantin);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SwitchToAnimator();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SwitchToPantin();
};
