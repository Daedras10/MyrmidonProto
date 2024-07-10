// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/RecordingGameInstance.h"
#include "Engine/DemoNetDriver.h"

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
