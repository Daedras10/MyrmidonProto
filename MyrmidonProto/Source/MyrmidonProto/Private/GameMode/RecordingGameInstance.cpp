// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/RecordingGameInstance.h"

#include "DataAsset/WorldDataAsset.h"
#include "Engine/DemoNetDriver.h"

void URecordingGameInstance::AskTimer(float Time)
{
	TimerHandle.Invalidate();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &URecordingGameInstance::TimerEnded, Time, false);
}

void URecordingGameInstance::CancelTimer()
{
	TimerHandle.Invalidate();
}

void URecordingGameInstance::TimerEnded()
{
	OnTimerDelegate.Broadcast();
}

void URecordingGameInstance::StartRecording(FString sequenceName)
{
	if (isRecording) return;
	isRecording = true;
	TArray<FString> Options;
	Options.Add("ReplayStreamerOverride=InMemoryNetworkReplayStreaming");
	StartRecordingReplay(sequenceName,"Friendly");
}

void URecordingGameInstance::StopRecording()
{
	if (!isRecording) return;
	isRecording = false;
	StopRecordingReplay();
}

void URecordingGameInstance::StartReplay(FString sequenceName)
{
	TArray<FString> Options;
	Options.Add("ReplayStreamerOverride=InMemoryNetworkReplayStreaming");
	PlayReplay(sequenceName);
	inReplay = true;
}

void URecordingGameInstance::JumpToPoint(float time)
{
	GetWorld()->GetDemoNetDriver()->GotoTimeInSeconds(time);
}

void URecordingGameInstance::Init()
{
	Super::Init();

	if (!UseDataAsset || !WorldDataAsset) return;
	IsPantin = WorldDataAsset->DebugSoloPlayerIsPantin;
}
