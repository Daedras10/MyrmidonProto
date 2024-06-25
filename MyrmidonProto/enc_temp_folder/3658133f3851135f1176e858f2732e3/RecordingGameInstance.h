// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RecordingGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API URecordingGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool isRecording = false;

	UFUNCTION(BlueprintCallable)
	void StartRecording(FString sequenceName);

	UFUNCTION(BlueprintCallable)
	void StopRecording();

	UFUNCTION(BlueprintCallable)
	void StartReplay(FString sequenceName);

	UFUNCTION(BlueprintCallable)
	void JumpToPoint(float time);
	
};
