// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/Bridge.h"

#include "Net/UnrealNetwork.h"

void ABridge::BeginPlay()
{
	Super::BeginPlay();
}

void ABridge::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABridge, BridgeIsMoving);
	DOREPLIFETIME(ABridge, Closing);
}

void ABridge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
