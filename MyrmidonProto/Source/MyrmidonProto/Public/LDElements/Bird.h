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
	WaitingForSafeSpot,
	Hovering,
	WindResistance
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

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FText GetDebugText();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Timer = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HoverTime = 3.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WindResistanceTime = 2.0f;

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


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	float CurrentPosAlongSpline;
	
};
