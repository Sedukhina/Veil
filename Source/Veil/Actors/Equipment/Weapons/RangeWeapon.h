// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Equipment/Weapons/Weapon.h"
#include "RangeWeapon.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class VEIL_API ARangeWeapon : public AWeapon
{
	GENERATED_BODY()

public:
	ARangeWeapon();

	void Shot();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UWeaponBarellComponent* WeaponBarell;
};
