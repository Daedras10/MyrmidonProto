// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LanguageDependent.generated.h"

enum class ELanguages : uint8;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULanguageDependent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MYRMIDONPROTO_API ILanguageDependent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetLanguage(ELanguages Language);

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
