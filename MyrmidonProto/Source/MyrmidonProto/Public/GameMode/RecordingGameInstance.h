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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
	float SaveVersion = 1.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
	int LanguageId = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
	int ScreenId = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
	int Resolution = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveSound")
	float Master = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveSound")
	float Music = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveSound")
	float Sfx = 1.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
	float Sensitivity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
	TArray<bool> UnlockedPages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveInfo")
	bool bDebugModeEnabled = false;
	
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int ViewDistance = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int AntiAliasing = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int PostProcess = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int Shadows = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int GlobalIllumination = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int Reflections = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int Textures = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int Effects = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int Foliage = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGraphics")
	int Shading = 3;
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDebugModeEnabled = false;

	void Init() override;
};
