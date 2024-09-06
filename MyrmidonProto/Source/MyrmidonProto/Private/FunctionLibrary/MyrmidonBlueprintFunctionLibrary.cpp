// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/MyrmidonBlueprintFunctionLibrary.h"


float UMyrmidonBlueprintFunctionLibrary::GetMinimalDistanceFromPointToRay(FVector Origin, FVector Forward,
	FVector Target)
{
	FVector u = Forward.GetSafeNormal();
	FVector v = (Target - Origin).GetSafeNormal();

	float angle = FMath::Acos(FVector::DotProduct(u, v));
	float distance = FVector::Dist(Origin, Target) * FMath::Sin(angle);

	return distance;
}
