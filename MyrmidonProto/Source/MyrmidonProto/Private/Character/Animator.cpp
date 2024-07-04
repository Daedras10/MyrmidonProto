// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Animator.h"

// Sets default values
AAnimator::AAnimator()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnimator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnimator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAnimator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

