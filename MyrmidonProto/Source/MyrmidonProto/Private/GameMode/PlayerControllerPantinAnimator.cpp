// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/PlayerControllerPantinAnimator.h"

void APlayerControllerPantinAnimator::ConvertInputs(FVector2D Inputs)
{
	InputsToCirclePositive(Inputs);
	
	if ( abs(Inputs.X) <= 0.01 )
	{
		if (Inputs.Y < 0) InputDirection(EDirection::Up);
		else InputDirection(EDirection::Down);
		return;
	}
	if ( abs(Inputs.Y) <= 0.01 )
	{
		if (Inputs.X > 0) InputDirection(EDirection::Right);
		else InputDirection(EDirection::Left);
		return;
	}

	// Diagonals
	if (Inputs.X > 0 && Inputs.Y < 0) InputDirection(EDirection::UpRight);
	if (Inputs.X > 0 && Inputs.Y > 0) InputDirection(EDirection::DownRight);
	if (Inputs.X < 0 && Inputs.Y < 0) InputDirection(EDirection::UpLeft);
	if (Inputs.X < 0 && Inputs.Y > 0) InputDirection(EDirection::DownLeft);
}

void APlayerControllerPantinAnimator::InputsToCirclePositive(FVector2D Inputs)
{
	// 0 for now
	if (DirectionsPositive.Num() == 0) return;
	

	
	auto Angle = FMath::Atan2(Inputs.Y, Inputs.X);
	auto AngleDeg = FMath::RadiansToDegrees(Angle);
	auto AngleDegNormalized = FMath::Fmod(AngleDeg + 360, 360);

	auto KindAngle = AngleDegNormalized + 15;
	if (KindAngle > 360) KindAngle = 360;
	
	auto Percent = KindAngle / 360.0f;
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Angle: %f, Percent: %f"), KindAngle, Percent*100));
	
}

void APlayerControllerPantinAnimator::InputDirection(const EDirection Direction)
{
	AddInputDirectionNegative(Direction);
	AddInputDirectionPositive(Direction);
	
	// const FString DirectionString = UEnum::GetValueAsString(Direction);
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, DirectionString);

	
	if (DirectionsPositive.Num() == 8)
	{
		OnCirclePositive();
		ClearDirections();
	}
	if (DirectionsNegative.Num() == 8)
	{
		OnCircleNegative();
		ClearDirections();
	}
	
}

void APlayerControllerPantinAnimator::AddInputDirectionPositive(EDirection Direction)
{
	if (DirectionsPositive.Contains(Direction)) return;

	if (DirectionsPositive.IsEmpty())
	{
		DirectionsPositive.Add(Direction);
		return;
	}

	if (Direction == NextDirection(DirectionsPositive.Last(), true) ) DirectionsPositive.AddUnique(Direction);
}

void APlayerControllerPantinAnimator::AddInputDirectionNegative(EDirection Direction)
{
	if (DirectionsNegative.Contains(Direction)) return;

	if (DirectionsNegative.IsEmpty())
	{
		DirectionsNegative.Add(Direction);
		return;
	}

	if (Direction == NextDirection(DirectionsNegative.Last(), false) ) DirectionsNegative.AddUnique(Direction);
}

EDirection APlayerControllerPantinAnimator::NextDirection(const EDirection Current, const bool Positive)
{
	switch (Current)
	{
	case EDirection::Up:
		return Positive ? EDirection::UpRight : EDirection::UpLeft;
	case EDirection::UpRight:
		return Positive ? EDirection::Right : EDirection::Up;
	case EDirection::Right:
		return Positive ? EDirection::DownRight : EDirection::UpRight;
	case EDirection::DownRight:
		return Positive ? EDirection::Down : EDirection::Right;
	case EDirection::Down:
		return Positive ? EDirection::DownLeft : EDirection::DownRight;
	case EDirection::DownLeft:
		return Positive ? EDirection::Left : EDirection::Down;
	case EDirection::Left:
		return Positive ? EDirection::UpLeft : EDirection::DownLeft;
	case EDirection::UpLeft:
		return Positive ? EDirection::Up : EDirection::Left;
	default:
		return Up;
	}
}

void APlayerControllerPantinAnimator::ClearDirections()
{
	DirectionsPositive.Empty();
	DirectionsNegative.Empty();
}

void APlayerControllerPantinAnimator::CircleNegativeCancelled_Implementation(int Progression)
{
}

void APlayerControllerPantinAnimator::CircleNegativeProgression_Implementation(int Progression)
{
}

void APlayerControllerPantinAnimator::CirclePositiveCancelled_Implementation(int Progression)
{
	
}

void APlayerControllerPantinAnimator::CirclePositiveProgression_Implementation(int Progression)
{
}

void APlayerControllerPantinAnimator::OnCircleNegative_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, TEXT("CIRCLE----- !!"));
}

void APlayerControllerPantinAnimator::OnCirclePositive_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, TEXT("CIRCLE+++++ !!"));
}
