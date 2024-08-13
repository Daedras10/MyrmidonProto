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

void APantinAnimatorPlayerState::SkipToNextCheckpoint()
{
	for (const auto Checkpoint : PantinCheckPointIndexes)
	{
		if (Checkpoint <= PantinCheckPointIndex) continue;

		PantinCheckPointIndex = Checkpoint;
		return;
	}
}

void APantinAnimatorPlayerState::SkipToPreviousCheckpoint()
{
	int NewCheckpoint = -1;
	for (const auto Checkpoint : PantinCheckPointIndexes)
	{
		if (Checkpoint >= PantinCheckPointIndex) continue;
		if (NewCheckpoint >= Checkpoint && NewCheckpoint != -1) continue;
		NewCheckpoint = Checkpoint;
	}
	if (NewCheckpoint == -1) return;
	PantinCheckPointIndex = NewCheckpoint;
}
