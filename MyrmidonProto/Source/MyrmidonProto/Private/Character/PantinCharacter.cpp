// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PantinCharacter.h"

#include "DataAsset/PantinDataAsset.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APantinCharacter::APantinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APantinCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PantinDataAsset == nullptr || !UseDataAsset)
	{
		MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
		return;
	}
	
	GetCharacterMovement()->GravityScale = PantinDataAsset->GravityScale;
	GetCharacterMovement()->MaxAcceleration = PantinDataAsset->MaxAcceleration;
	GetCharacterMovement()->BrakingFrictionFactor = PantinDataAsset->BrakingFrictionFactor;
	GetCharacterMovement()->Mass = PantinDataAsset->Mass;

	GetCharacterMovement()->MaxStepHeight = PantinDataAsset->MaxStepHeight;
	GetCharacterMovement()->SetWalkableFloorAngle(PantinDataAsset->WalkableFloorAngle);
	GetCharacterMovement()->GroundFriction = PantinDataAsset->GroundFriction;
	GetCharacterMovement()->MaxWalkSpeed = PantinDataAsset->MaxWalkSpeed;

	GetCharacterMovement()->JumpZVelocity = PantinDataAsset->JumpZVelocity;
	GetCharacterMovement()->BrakingDecelerationFalling = PantinDataAsset->BrakingDecelerationFalling;
	GetCharacterMovement()->AirControl = PantinDataAsset->AirControl;
	GetCharacterMovement()->AirControlBoostMultiplier = PantinDataAsset->AirControlBoostMultiplier;
	GetCharacterMovement()->AirControlBoostVelocityThreshold = PantinDataAsset->AirControlBoostVelocityThreshold;
	GetCharacterMovement()->FallingLateralFriction = PantinDataAsset->FallingLateralFriction;

	MaxGravity = PantinDataAsset->MaxGravity;
	MinGravity = PantinDataAsset->MinGravity;
	FunkyGravityDuration = PantinDataAsset->FunkyGravityDuration;
	CoyoteTime = PantinDataAsset->CoyoteTime;
	MaxSprintSpeed = PantinDataAsset->MaxSprintSpeed;

	WindPower = PantinDataAsset->WindPower;
	WindMaxHit = PantinDataAsset->WindMaxHit;
	WindDirection = PantinDataAsset->WindDirection;
	OppositInputsMult = PantinDataAsset->OppositInputsMult;

	ClimbSpeed = PantinDataAsset->ClimbSpeed;
	ClimbMinArea = PantinDataAsset->ClimbMinArea;
	ClimbPantinHeight = PantinDataAsset->ClimbPantinHeight;

	
	MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

// Called every frame
void APantinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APantinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APantinCharacter::ActivateSprint(const bool bActivate)
{
	if (bActivate == IsSprinting) return;

	IsSprinting = bActivate;
	GetCharacterMovement()->MaxWalkSpeed = IsSprinting ? MaxSprintSpeed : MaxWalkSpeed;
}

