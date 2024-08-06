// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MenuGameModeBase.h"

void AMenuGameModeBase::ButtonClicked(bool ClickPantin, bool IsP1)
{
	if (IsP1)
	{
		if (ClickPantin)
		{
			Player1Choice = Player1Choice != EPlayerChoice::Pantin ? EPlayerChoice::Pantin : EPlayerChoice::None;
			return;
		}
		Player1Choice = Player1Choice != EPlayerChoice::Animator ? EPlayerChoice::Animator : EPlayerChoice::None;
		return;
	}

	if (ClickPantin)
	{
		Player2Choice = Player2Choice != EPlayerChoice::Pantin ? EPlayerChoice::Pantin : EPlayerChoice::None;
		return;
	}
	Player2Choice = Player2Choice != EPlayerChoice::Animator ? EPlayerChoice::Animator : EPlayerChoice::None;
}

void AMenuGameModeBase::UpdateRoles(bool ClickPantin, bool IsP1)
{
	ButtonClicked(ClickPantin, IsP1);

	Player1Img = -1;
	Player2Img = -1;

	if (Player1Choice != EPlayerChoice::None) Player1Img = Player1Choice == EPlayerChoice::Pantin ? 1 : 2;

	if (Player2Choice == EPlayerChoice::None) return;

	Player2Img = Player2Choice == EPlayerChoice::Pantin ? 1 : 2;
	if (Player1Img != Player2Img) return;
	
	Player2Img *= 11;
}
