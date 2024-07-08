// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/Bird.h"

#include "Net/UnrealNetwork.h"

// Sets default values
ABird::ABird()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
}

void ABird::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABird, CurrentAction);
	DOREPLIFETIME(ABird, IdleLocation);
	DOREPLIFETIME(ABird, CurrentPosAlongSpline);
}

FText ABird::GetDebugText()
{
	switch (CurrentAction)
	{
		case EBirdAction::Idle:
			return FText::FromString("Idle");
		case EBirdAction::FlyingAway:
			return FText::FromString("FlyingAway");
		case EBirdAction::GoingBack:
			return FText::FromString("GoingBack");
		case EBirdAction::WaitingForSafeSpot:
			return FText::FromString("WaitingForSafeSpot");
		case EBirdAction::Hovering:
			return FText::FromString("Hovering");
		case EBirdAction::WindResistance:
			return FText::FromString("WindResistance");
		default:
			return FText::FromString("Unknown");
	}
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}