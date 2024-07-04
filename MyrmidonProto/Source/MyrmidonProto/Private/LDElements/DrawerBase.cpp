// Fill out your copyright notice in the Description page of Project Settings.


#include "LDElements/DrawerBase.h"

#include "DataAsset/DrawerBaseDataAsset.h"

// Sets default values
ADrawerBase::ADrawerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADrawerBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (DataAsset == nullptr || !UseDataAsset) return;

	Speed = DataAsset->Speed;
	MinimalPercentDistance = DataAsset->MinimalPercentDistance;
	ModeFollowMouse = DataAsset->ModeFollowMouse;
	DelayBeforeMovement = DataAsset->DelayBeforeMovement;
}

// Called every frame
void ADrawerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

