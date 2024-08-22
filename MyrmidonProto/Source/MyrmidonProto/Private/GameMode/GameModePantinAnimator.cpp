// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GameModePantinAnimator.h"

bool AGameModePantinAnimator::CanEndGame()
{
	if (IsPlayerPresent(true) && !PantinEndOfGame) return false;
	if (IsPlayerPresent(false) && !AnimatorEndOfGame) return false;

	if (IsPlayerPresent(true) && IsPlayerPresent(false))
	{
		if (PantinEndOfGame && AnimatorEndOfGame) return true;
		return false;
	}

	return true;
}
