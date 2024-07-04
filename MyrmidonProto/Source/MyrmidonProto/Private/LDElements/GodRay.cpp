// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/GodRay.h"

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

	if (DataAsset == nullptr || !UseDataAsset) return;
}

// Called every frame
void AGodRay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

