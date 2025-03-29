// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Equipment/Weapons/Components/WeaponBarellComponent.h"
#include <VeilTypes.h>

// Sets default values for this component's properties
UWeaponBarellComponent::UWeaponBarellComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UWeaponBarellComponent::Shot(FVector ShotStart, FVector ShotDirection, AController* Controller)
{
	//FVector ShotStart = GetComponentLocation();
	FVector ShotEnd = ShotStart + FiringRange * ShotDirection;
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, ShotStart, ShotEnd, ECC_Projectile);
	DrawDebugLine(GetWorld(), ShotStart, ShotEnd, FColor(255, 0, 0), false, -1, 0, 3);
}



