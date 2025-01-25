// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/SteamAchievementComponent.h"

// Sets default values for this component's properties
USteamAchievementComponent::USteamAchievementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USteamAchievementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

FString USteamAchievementComponent::EnumToStringAchievement(ESteamAchievement Achievement)
{
	switch (Achievement) {
	case ESteamAchievement::ACHIEVEMENT_ACTION:
		return "ACHIEVEMENT_ACTION";
	case ESteamAchievement::ACHIEVEMENT_REBOOT:
		return "ACHIEVEMENT_REBOOT";
	case ESteamAchievement::ACHIEVEMENT_SILENCE:
		return "ACHIEVEMENT_SILENCE";
	case ESteamAchievement::ACHIEVEMENT_CUT:
		return "ACHIEVEMENT_CUT";
	case ESteamAchievement::ACHIEVEMENT_TAKE2:
		return "ACHIEVEMENT_TAKE2";
	case ESteamAchievement::ACHIEVEMENT_FIRSTMASK:
		return "ACHIEVEMENT_FIRSTMASK";
	case ESteamAchievement::ACHIEVEMENT_ANIMALS:
		return "ACHIEVEMENT_ANIMALS";
	case ESteamAchievement::ACHIEVEMENT_TAKE10:
		return "ACHIEVEMENT_TAKE10";
	case ESteamAchievement::ACHIEVEMENT_BLOOPERS:
		return "ACHIEVEMENT_BLOOPERS";
	case ESteamAchievement::ACHIEVEMENT_FINISHDEMO:
		return "ACHIEVEMENT_FINISHDEMO";
	case ESteamAchievement::ACHIEVEMENT_SECRET1:
		return "ACHIEVEMENT_SECRET1";
	case ESteamAchievement::ACHIEVEMENT_SECRET2:
		return "ACHIEVEMENT_SECRET2";
	case ESteamAchievement::ACHIEVEMENT_SECRET3:
		return "ACHIEVEMENT_SECRET3";
	case ESteamAchievement::ACHIEVEMENT_SECRET4:
		return "ACHIEVEMENT_SECRET4";
	case ESteamAchievement::ACHIEVEMENT_SECRET5:
		return "ACHIEVEMENT_SECRET5";
	}
	return "None";
}


// Called every frame
void USteamAchievementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

