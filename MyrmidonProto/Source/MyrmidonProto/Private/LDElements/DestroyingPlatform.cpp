// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/DestroyingPlatform.h"

#include "DataAsset/DestroyingPlatformDataAsset.h"

// Sets default values
ADestroyingPlatform::ADestroyingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADestroyingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	if (DataAsset == nullptr || !UseDataAsset) return;

	DisapearDelay = DataAsset->DisapearDelay;
	RespawnDelay = DataAsset->RespawnDelay;
	PlatformScale = DataAsset->PlatformScale;
}

// Called every frame
void ADestroyingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

