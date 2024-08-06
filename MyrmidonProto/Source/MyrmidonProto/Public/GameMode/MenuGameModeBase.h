// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGameModeBase.generated.h"

UENUM(BlueprintType)
enum class EPlayerChoice : uint8
{
	None,
	Pantin,
	Animator,
};

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API AMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	EPlayerChoice Player1Choice = EPlayerChoice::None;

	UPROPERTY(BlueprintReadWrite)
	EPlayerChoice Player2Choice = EPlayerChoice::None;
	
	UPROPERTY(BlueprintReadWrite)
	int Player1Img = -1;

	UPROPERTY(BlueprintReadWrite)
	int Player2Img = -1;

	UPROPERTY(BlueprintReadWrite)
	bool P1Ready = false;

	UPROPERTY(BlueprintReadWrite)
	bool P2Ready = false;

	UPROPERTY(BlueprintReadWrite)
	float TimeBeforeStart = 5.0f;
	
private:
	void ButtonClicked(bool ClickPantin, bool IsP1);

	UFUNCTION(BlueprintCallable)
	void UpdateRoles(bool ClickPantin, bool IsP1);
};
