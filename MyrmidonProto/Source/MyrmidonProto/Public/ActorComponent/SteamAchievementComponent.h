// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SteamAchievementComponent.generated.h"

UENUM(Blueprintable)
enum class ESteamAchievement : uint8
{
	ACHIEVEMENT_NONE,
	ACHIEVEMENT_ACTION,
	ACHIEVEMENT_REBOOT,
	ACHIEVEMENT_SILENCE,
	ACHIEVEMENT_CUT,
	ACHIEVEMENT_TAKE2,
	ACHIEVEMENT_FIRSTMASK,
	ACHIEVEMENT_ANIMALS,
	ACHIEVEMENT_TAKE10,
	ACHIEVEMENT_BLOOPERS,
	ACHIEVEMENT_FINISHDEMO,
	ACHIEVEMENT_SECRET1,
	ACHIEVEMENT_SECRET2,
	ACHIEVEMENT_SECRET3,
	ACHIEVEMENT_SECRET4,
	ACHIEVEMENT_SECRET5
};
	

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class MYRMIDONPROTO_API USteamAchievementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USteamAchievementComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) void AddSteamAchievement(ESteamAchievement Achievement);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure) FString EnumToStringAchievement(ESteamAchievement Achievement);
};
