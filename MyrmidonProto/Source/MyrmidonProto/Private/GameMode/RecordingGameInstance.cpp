// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordingGameInstance.h"
#include "Engine/DemoNetDriver.h"

void URecordingGameInstance::StartRecording(FString sequenceName)
{
	if (isRecording) return;
	isRecording = true;
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
	PlayReplay(sequenceName);
	inReplay = true;
}

void URecordingGameInstance::JumpToPoint(float time)
{
	GetWorld()->GetDemoNetDriver()->GotoTimeInSeconds(time);
}
