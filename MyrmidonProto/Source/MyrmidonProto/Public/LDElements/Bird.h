// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Windable.h"
#include "LDElements/Base/SwitchBase.h"
#include "Bird.generated.h"

UENUM(BlueprintType)
enum class EBirdAction : uint8
{
	Idle,
	FlyingAway,
	GoingBack,
	WaitingForSafeSpot
};

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API ABird : public ASwitchBase, public IWindable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABird();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WaitingTime = 5.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool BaseIsexposed = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	FVector IdleLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	EBirdAction CurrentAction = EBirdAction::Idle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool WindIsActive = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector WindDirection;
	
};
