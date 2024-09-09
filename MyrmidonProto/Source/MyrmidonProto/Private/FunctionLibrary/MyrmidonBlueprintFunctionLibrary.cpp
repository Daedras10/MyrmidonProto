// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/MyrmidonBlueprintFunctionLibrary.h"


FDistanceData UMyrmidonBlueprintFunctionLibrary::GetMinimalDistanceFromPointToRay(FVector Origin, FVector Forward,
	FVector Target)
{
	FVector u = Forward.GetSafeNormal();
	FVector v = (Target - Origin).GetSafeNormal();

	float angle = FMath::Acos(FVector::DotProduct(u, v));
	float distance = FVector::Dist(Origin, Target) * FMath::Sin(angle);

	FDistanceData data = FDistanceData(distance, angle);
	return data;
}

bool UMyrmidonBlueprintFunctionLibrary::IsDistanceDataValid(FDistanceData Data, float MaxDistance, float MaxAngle)
{
	if (abs(Data.Distance) > MaxDistance || abs(Data.Angle) > MaxAngle) return false;
	return true;
}
