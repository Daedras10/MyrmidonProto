// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Windable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UWindable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYRMIDONPROTO_API IWindable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetWindDirection(FVector WindDirection, float WindStrength);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetActiveWind(bool bIsActive);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool SetActiveOutsideTriger();
};
