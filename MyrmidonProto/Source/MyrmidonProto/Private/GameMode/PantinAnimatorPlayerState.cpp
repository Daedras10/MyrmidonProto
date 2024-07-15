// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/PantinAnimatorPlayerState.h"

#include "DataAsset/WorldDataAsset.h"
#include "Net/UnrealNetwork.h"

void APantinAnimatorPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (!UseDataAsset || !WorldDataAsset) return;

	PantinCheckPointIndex = WorldDataAsset->DebugCurrentCheckpointIndex;
}

void APantinAnimatorPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APantinAnimatorPlayerState, IsPantin);
	DOREPLIFETIME(APantinAnimatorPlayerState, PantinCheckPointIndex);
}
