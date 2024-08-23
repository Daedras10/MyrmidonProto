// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/PlayerControllerPantinAnimator.h"

void APlayerControllerPantinAnimator::ConvertInputs(FVector2D Inputs)
{
	InputsToCirclePositive(Inputs);
	InputsToCircleNegative(Inputs);

	//Start timer to cancel circle with CircleInputTimeoutHandle
	GetWorld()->GetTimerManager().ClearTimer(CircleInputTimeoutHandle);
	GetWorld()->GetTimerManager().SetTimer(CircleInputTimeoutHandle, this, &APlayerControllerPantinAnimator::CancelCircle, CircleNotInteractingMaxTime, false);

	
	return;
	
	if ( FMath::Abs(Inputs.X) <= 0.01 )
	{
		if (Inputs.Y < 0) InputDirection(EDirection::Up);
		else InputDirection(EDirection::Down);
		return;
	}
	if ( FMath::Abs(Inputs.Y) <= 0.01 )
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

void APlayerControllerPantinAnimator::InputsToCirclePositive(const FVector2D Inputs)
{
	const auto Angle = FMath::Atan2(Inputs.Y, Inputs.X);
	const auto AngleDeg = FMath::RadiansToDegrees(Angle);
	const auto AngleDegNormalized = FMath::Fmod(AngleDeg + 360, 360);

	if (CircleStartAngle < 0)
	{
		CircleStartAngle = AngleDegNormalized;
		CurrentProgressionPositive = 0;
		CurrentProgressionNegative = 0;
		CirclePositiveProgression(0);
		CircleNegativeProgression(0);
		return;
	}
	
	auto Progression = AngleDegNormalized + CircleStartAngle;
	Progression = FMath::Fmod(Progression + 360, 360);
	
	auto KindAngle = Progression + AngleKindness;
	if (KindAngle > 360) KindAngle = 360;

	const auto Percent = KindAngle / 360.0f;

	if (FMath::Abs(Percent - CurrentProgressionPositive) > ProgressionAllowed ) return;

	CurrentProgressionPositive = Percent;
	CirclePositiveProgression(Percent);

	if (Percent == 1.0f)
	{
		OnCirclePositive();
		//ClearDirections();
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Percent: %f ; %f"), Percent*100.0f, CircleStartAngle));
}

/*
*auto Progression = AngleDegNormalized - CircleStartAngle;
	Progression = FMath::Fmod(Progression + 360, 360);
	
	auto KindAngle = Progression + AngleKindness;
	//if (KindAngle > 360) KindAngle = 360;

	auto Percent = KindAngle / 360.0f;

	//if (Percent > 1) Percent -= 1;
	auto ProgressSinceLast = Percent - CurrentProgressionPositive;
	//if (ProgressSinceLast < 0) return;

	//if (ProgressSinceLast >= 0)
		CurrentProgressionPositive = Percent;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%f >>> (%f)   : %f / %f ; %f"), Percent, CurrentProgressionPositive, CircleStartAngle, KindAngle, AngleDegNormalized));
	return;

	//if (FMath::Abs(Percent - CurrentProgressionPositive) > ProgressionAllowed || (CurrentProgressionPositive + Percent)-1 > CurrentProgressionPositive)
	if (ProgressSinceLast > ProgressionAllowed)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%f"), ProgressSinceLast));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%f - %f; %f > %f"), Percent, CurrentProgressionPositive, FMath::Abs(Percent - CurrentProgressionPositive), ProgressionAllowed));
		return;
	}
	if (ProgressSinceLast < 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("%f"), ProgressSinceLast));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%f - %f; %f > %f"), Percent, CurrentProgressionPositive, FMath::Abs(Percent - CurrentProgressionPositive), ProgressionAllowed));
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Percent: %f"), Percent*100.0f));

	CurrentProgressionPositive = Percent;
	CirclePositiveProgression(Percent);

	if (Percent == 1.0f)
	{
		OnCirclePositive();
		//ClearDirections();
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Percent: %f ; %f"), Percent*100.0f, CircleStartAngle));
 */

void APlayerControllerPantinAnimator::InputsToCircleNegative(FVector2D Inputs)
{
	const auto Angle = FMath::Atan2(Inputs.Y, Inputs.X);
	const auto AngleDeg = FMath::RadiansToDegrees(Angle);
	const auto AngleDegNormalized = FMath::Fmod(AngleDeg + 360, 360);

	if (CircleStartAngle < 0)
	{
		CircleStartAngle = AngleDegNormalized;
		CurrentProgressionPositive = 0;
		CurrentProgressionNegative = 0;
		CirclePositiveProgression(0);
		CircleNegativeProgression(0);
		return;
	}
	
	auto Progression = AngleDegNormalized - CircleStartAngle;
	Progression = FMath::Fmod(Progression + 360, 360);
	
	auto KindAngle = Progression - AngleKindness;
	if (KindAngle < 0) KindAngle = 0;

	const auto Percent = 1 + (KindAngle / -360.0f);
	

	if (FMath::Abs(Percent - CurrentProgressionNegative) > ProgressionAllowed ) return;

	CurrentProgressionNegative = Percent;
	CircleNegativeProgression(Percent);

	if (Percent == 1.0f)
	{
		OnCircleNegative();
		//ClearDirections();
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Percent: %f ; %f"), Percent*100.0f, CircleStartAngle));
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

void APlayerControllerPantinAnimator::AddInputDirectionPositive(const EDirection Direction)
{
	if (DirectionsPositive.Contains(Direction)) return;

	if (DirectionsPositive.IsEmpty())
	{
		DirectionsPositive.Add(Direction);
		return;
	}

	if (Direction == NextDirection(DirectionsPositive.Last(), true) ) DirectionsPositive.AddUnique(Direction);
}

void APlayerControllerPantinAnimator::AddInputDirectionNegative(const EDirection Direction)
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
	CircleStartAngle = -1.0f;

	CurrentProgressionNegative = 0;
	CurrentProgressionPositive = 0;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Clear Directions"));
}

void APlayerControllerPantinAnimator::CancelCircle()
{
	CirclePositiveCancelled(CurrentProgressionPositive);
	CircleNegativeCancelled(CurrentProgressionNegative);
	ClearDirections();
}

void APlayerControllerPantinAnimator::CircleNegativeCancelled_Implementation(float Progression)
{
}

void APlayerControllerPantinAnimator::CircleNegativeProgression_Implementation(float Progression)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Percent: %f"), Progression*100.0f));
}

void APlayerControllerPantinAnimator::CirclePositiveCancelled_Implementation(float Progression)
{
	
}

void APlayerControllerPantinAnimator::CirclePositiveProgression_Implementation(float Progression)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Percent: %f"), Progression*100.0f));
}

void APlayerControllerPantinAnimator::OnCircleNegative_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, TEXT("CIRCLE----- !!"));
}

void APlayerControllerPantinAnimator::OnCirclePositive_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, TEXT("CIRCLE+++++ !!"));
}
