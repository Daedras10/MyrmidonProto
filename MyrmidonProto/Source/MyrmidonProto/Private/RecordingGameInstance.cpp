// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordingGameInstance.h"

void URecordingGameInstance::StartRecording()
{
	if (isRecording) return;
	isRecording = true;
	StartRecordingReplay("Test","TestFriendly");
}

void URecordingGameInstance::StopRecording()
{
	if (!isRecording) return;
	isRecording = false;
	StopRecordingReplay();
}

void URecordingGameInstance::StartReplay()
{
	PlayReplay("Test");
}
