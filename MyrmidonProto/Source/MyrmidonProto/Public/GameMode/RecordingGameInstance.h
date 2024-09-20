// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedFriendsGameInstance.h"
#include "Enums.h"
#include "Engine/GameInstance.h"
#include "RecordingGameInstance.generated.h"


USTRUCT(BlueprintType)
struct FGameSaveData
{
	GENERATED_BODY()

public:
	FGameSaveData() : LanguageId(0), Master(1.0f), Music(1.0f), Sfx(1.0f), Sensitivity(1.0f)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveID")
	int LanguageId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveID")
	float Master = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveID")
	float Music = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveID")
	float Sfx = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveID")
	float Sensitivity = 1.0f;
	
};


enum class ELanguages : uint8;
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ELanguages Languages = ELanguages::English;

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
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameSaveData GameSaveData;

	void Init() override;
};
