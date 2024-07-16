// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mole.generated.h"

UCLASS()
class MYRMIDONPROTO_API AMole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	bool Moving = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	bool GoingUp = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool StrartUp = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBeforeGoingDown = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 1;


	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MoleHeightMult = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float UpHeight = 500;

	
	
};
