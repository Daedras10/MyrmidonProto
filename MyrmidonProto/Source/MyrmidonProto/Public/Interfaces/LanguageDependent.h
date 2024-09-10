// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LanguageDependent.generated.h"

class AStaticMeshActor;
class ATextRenderActor;
enum class ELanguages : uint8;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULanguageDependent : public UInterface
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FLanguageText
{
	GENERATED_BODY()

public:
	FLanguageText(): TextActor(nullptr)
	{
		English = "";
		French = "";
	}


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Language")
	FString English;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Language")
	FString French;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Language")
	ATextRenderActor* TextActor;
};


USTRUCT(BlueprintType)
struct FInputVisuals
{
	GENERATED_BODY()

public:
	FInputVisuals(): InputKeayboardMaterial(nullptr), InputGamepadMaterial(nullptr), Mesh(nullptr)
	{
	}


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")
	UMaterial* InputKeayboardMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")
	UMaterial* InputGamepadMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs")
	AStaticMeshActor* Mesh;
};


/**
 * 
 */
class MYRMIDONPROTO_API ILanguageDependent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetLanguage(ELanguages Language);

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
