// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Animator.generated.h"

UCLASS()
class MYRMIDONPROTO_API AAnimator : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void ActivateSprint(const bool bActivate);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxWalkSpeed = 2500.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxSprintSpeed = 3500.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CameraNodeRyhtmMultWalk = 10.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CameraNodeRyhtmMultSprint = 12.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CameraNodeForceMultWalk = 10.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CameraNodeForceMultSprint = 20.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CameraNodeMultiplier2 = 10.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsSprinting = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* ObjectInHand;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* HoveredObject;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ArmReach = 5000.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxGrabbedRange = 3000.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxStepHeight = 600.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float GravityScale = 15.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	bool CanMove = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	bool CanBeMovedByOthers = false; //TODO remove this if GDs have no use for it

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* InteractorA;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* InteractorB;
};
