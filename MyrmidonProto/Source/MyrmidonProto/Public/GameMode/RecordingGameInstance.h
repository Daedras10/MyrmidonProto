// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedFriendsGameInstance.h"
#include "Engine/GameInstance.h"
#include "RecordingGameInstance.generated.h"

class UWorldDataAsset;
/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API URecordingGameInstance : public UAdvancedFriendsGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool isRecording = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool inReplay = false;

	UPROPERTY(BlueprintReadWrite)
	bool IsPantin = false;

	UFUNCTION(BlueprintCallable)
	void StartRecording(FString sequenceName);

	UFUNCTION(BlueprintCallable)
	void StopRecording();

	UFUNCTION(BlueprintCallable)
	void StartReplay(FString sequenceName);

	UFUNCTION(BlueprintCallable)
	void JumpToPoint(float time);



	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWorldDataAsset* WorldDataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;

	void Init() override;
};
