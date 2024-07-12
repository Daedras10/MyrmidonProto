// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LDElements/Base/SwitchBase.h"
#include "Bridge.generated.h"

/**
 * 
 */
UCLASS()
class MYRMIDONPROTO_API ABridge : public ASwitchBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Bridge1Scale = FVector(1.0f, 1.0f, 1.0f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Bridge2Scale = FVector(1.0f, 1.0f, 1.0f);
	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	bool BridgeIsMoving = false;
	
	UPROPERTY(BlueprintReadWrite, Replicated)
	bool Closing = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool StartClosed = true;
};
