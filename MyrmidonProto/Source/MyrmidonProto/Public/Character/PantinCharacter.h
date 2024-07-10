// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Windable.h"
#include "PantinCharacter.generated.h"

class UPantinDataAsset;

UCLASS()
class MYRMIDONPROTO_API APantinCharacter : public ACharacter, public IWindable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APantinCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FVector GetFirstVelocityToCheck();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FVector GetFirstForwardToCheck();

	UFUNCTION(BlueprintCallable)
	virtual void AddLastVelocityAndForward();

	UFUNCTION(BlueprintCallable)
	virtual void ClearVelocityAndForwardMemory();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void ActivateSprint(const bool bActivate);


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UPantinDataAsset* PantinDataAsset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool UseDataAsset = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxGravity = 2.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinGravity = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FunkyGravityDuration = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CoyoteTime = 0.1f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxWalkSpeed = 500.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxSprintSpeed = 900.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsSprinting = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InvertVelocityMargin = -0.98;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float JumpBufferMax = 0.0;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float JumpBufferCurrent = 0.0;


	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	float WindPower = 10.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	int WindMaxHit = 3;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	float OppositInputsMult = 0.6f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Wind")
	FVector WindDirection = FVector(1.0f, 0.0f, 0.0f);



	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Climb")
	float ClimbPantinHeight = 60.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Climb")
	float ClimbMinArea = 50.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Climb")
	float ClimbSpeed = 5.0f;


	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> LastVelocities = TArray<FVector>();
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> LastForwards = TArray<FVector>();

	UPROPERTY(BlueprintReadWrite)
	int FramesToCheckForInvertVelocity;

	UPROPERTY(BlueprintReadWrite)
	bool IsAlive = true;

};
