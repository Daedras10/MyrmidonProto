// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/GodRay.h"

#include "DataAsset/GodRayDataAsset.h"

// Sets default values
AGodRay::AGodRay()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGodRay::BeginPlay()
{
	Super::BeginPlay();

	UpdateFromDataAsset();
}

void AGodRay::UpdateFromDataAsset()
{
	if (DataAsset == nullptr || !UseDataAsset) return;

	JumpPower = DataAsset->JumpPower;
	FallingSpeed = DataAsset->FallingSpeed;
	FallingMaxSpeed = DataAsset->FallingMaxSpeed;
	RayAttraction = DataAsset->RayAttraction;
	SpotSpeed = DataAsset->SpotSpeed;
	//RayWidthScale = DataAsset->RayWidthScale;
	// MaxHeight = DataAsset->MaxHeight;
	// InitialPosition = DataAsset->InitialPosition;
}

void AGodRay::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateFromDataAsset();
}

// Called every frame
void AGodRay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

