// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/PlayerControllerPantinAnimator.h"

void APlayerControllerPantinAnimator::ConvertInputs(FVector2D Inputs)
{
	return;
	
	if ( abs(Inputs.X) <= 0.01 )
	{
		if (Inputs.Y < 0) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Up"));
		else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Down"));
		return;
	}
	if ( abs(Inputs.Y) <= 0.01 )
	{
		if (Inputs.X > 0) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Right"));
		else GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Left"));
		return;
	}

	// Diagonals
	if (Inputs.X > 0 && Inputs.Y < 0) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Up Right"));
	if (Inputs.X > 0 && Inputs.Y > 0) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Down Right"));
	if (Inputs.X < 0 && Inputs.Y < 0) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Up Left"));
	if (Inputs.X < 0 && Inputs.Y > 0) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Down Left"));
}
