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
	JumpMaxHoldTime = PantinDataAsset->JumpMaxHoldTime;
	JumpBufferMax = PantinDataAsset->JumpBuffer;

	MaxGravity = PantinDataAsset->MaxGravity;
	MinGravity = PantinDataAsset->MinGravity;
	FunkyGravityDuration = PantinDataAsset->FunkyGravityDuration;
	CoyoteTime = PantinDataAsset->CoyoteTime;
	MaxSprintSpeed = PantinDataAsset->MaxSprintSpeed;
	InvertVelocityMargin = PantinDataAsset->InvertVelocityMargin;

	WindPower = PantinDataAsset->WindPower;
	WindMaxHit = PantinDataAsset->WindMaxHit;
	WindDirection = PantinDataAsset->WindDirection;
	OppositInputsMult = PantinDataAsset->OppositInputsMult;

	ClimbSpeed = PantinDataAsset->ClimbSpeed;
	ClimbMinArea = PantinDataAsset->ClimbMinArea;
	ClimbPantinHeight = PantinDataAsset->ClimbPantinHeight;
	
	MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;

	LastVelocities = TArray<FVector>();
	LastForwards = TArray<FVector>();
	FramesToCheckForInvertVelocity = PantinDataAsset->FramesToCheckForInvertVelocity;
}

FVector APantinCharacter::GetFirstVelocityToCheck()
{
	if (LastVelocities.Num() == 0) return GetCharacterMovement()->Velocity;

	return LastVelocities[0];
}

FVector APantinCharacter::GetFirstForwardToCheck()
{
	if (LastForwards.Num() == 0) return GetMesh()->GetForwardVector();
	
	return LastForwards[0];
}

void APantinCharacter::AddLastVelocityAndForward()
{
	const auto Velocity = GetCharacterMovement()->Velocity;
	const auto Forward = GetMesh()->GetForwardVector();
	
	LastVelocities.Add(Velocity);
	LastForwards.Add(Forward);
	if (LastVelocities.Num() <= FramesToCheckForInvertVelocity) return;

	LastVelocities.RemoveAt(0);
	LastForwards.RemoveAt(0);
}

void APantinCharacter::ClearVelocityAndForwardMemory()
{
	LastVelocities.Empty();
	LastForwards.Empty();
}

FVector APantinCharacter::ConvertInputToWind(const FVector Input)
{
	if (!WindIsActive)
	{
		RunningAgainstWind = false;
		RunningWithWind = false;
		LastRunningAgainstWind = RunningAgainstWind;
		return Input;
	}

	const auto WindNormalized = WindDirection.GetSafeNormal();
	const auto InputNormalized = FVector(Input.X, Input.Y, 0.0f).GetSafeNormal();

	const auto Dot = FVector::DotProduct(WindNormalized, InputNormalized);

	if (Dot > 0.0f)
	{
		RunningAgainstWind = false;
		RunningWithWind = true;
		LastRunningAgainstWind = RunningAgainstWind;
		return Input;
	}

	const auto DotX = FVector::DotProduct(WindNormalized, FVector(-1.0f, 0.0f, 0.0f));
	const auto DotY = FVector::DotProduct(WindNormalized, FVector(0.0f, -1.0f, 0.0f));

	auto Multiplicators = FVector(1.0f, 1.0f, 1.0f);
	Multiplicators.X = FMath::Max(1-DotX, 0.1f);
	Multiplicators.Y = FMath::Max(1-DotY, 0.1f);
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("MultX: %f, MultY: %f"), Mults.X, Mults.Y));

	auto NewInputs = FVector(Input.X * Multiplicators.X, Input.Y * Multiplicators.Y, Input.Z);
	RunningAgainstWind = true;
	RunningWithWind = false;
	LastRunningAgainstWind = RunningAgainstWind;
	
	return NewInputs;
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

void APantinCharacter::ActivateSprint_Implementation(const bool bActivate)
{
	if (bActivate == IsSprinting) return;

	IsSprinting = bActivate;
	GetCharacterMovement()->MaxWalkSpeed = IsSprinting ? MaxSprintSpeed : MaxWalkSpeed;
}

