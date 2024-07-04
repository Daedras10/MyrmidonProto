// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/LateralBar.h"

#include "DataAsset/LateralBarDataAsset.h"

// Sets default values
ALateralBar::ALateralBar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALateralBar::BeginPlay()
{
	Super::BeginPlay();
	
	if (DataAsset == nullptr || !UseDataAsset) return;

	Angle = DataAsset->Angle;
	Velocity = DataAsset->Velocity;
	Drag = DataAsset->Drag;
	InputForce = DataAsset->InputForce;
	ExitForce = DataAsset->ExitForce;
	MaxVelocity = DataAsset->MaxVelocity;
}

// Called every frame
void ALateralBar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

