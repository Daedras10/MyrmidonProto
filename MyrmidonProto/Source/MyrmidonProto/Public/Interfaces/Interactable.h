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

USTRUCT(Blueprintable)
struct FSTRUC_InputInfos {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	 bool twoInputs;
	UPROPERTY(BlueprintReadWrite)
	 FString inputOneText;
	UPROPERTY(BlueprintReadWrite)
	 FString inputTwoText;
	
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* inputIconOne;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* inputIconTwo;
	
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* inputIconOneKeyboard;
	UPROPERTY(BlueprintReadWrite)
	UTexture2D* inputIconTwoKeyboard;
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
	void ShowAim();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HideAim();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void LockAim(bool val);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Moved(FVector position);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHighlighted(bool bShouldHighlight);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	int GetCorkBoardIndex();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	float GetCorkOffset();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FVector GetInterractPoint();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FVector GetInterractOffset();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FVector GetRectMargins();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FSTRUC_InputInfos GetInputInfos(bool& bDisplay);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool IsPickable();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsInteractable();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool IsPicked();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool PickableShouldLerp();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetPickableShouldLerp(bool bShouldLerp);
};

