// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/Mole.h"

#include "Net/UnrealNetwork.h"

// Sets default values
AMole::AMole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMole::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMole, Moving);
	DOREPLIFETIME(AMole, GoingUp);
}

