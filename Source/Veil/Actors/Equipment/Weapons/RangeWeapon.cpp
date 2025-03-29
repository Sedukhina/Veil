// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Equipment/Weapons/RangeWeapon.h"
#include "RangeWeapon.h"
#include "Actors/Equipment/Weapons/Components/WeaponBarellComponent.h"
#include <Characters/BaseCharacter.h>

ARangeWeapon::ARangeWeapon()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponRoot"));

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponBarell = CreateDefaultSubobject<UWeaponBarellComponent>(TEXT("Weapon Barell"));
	WeaponBarell->SetupAttachment(WeaponMesh, WeaponMuzzleSocket);
}


void ARangeWeapon::Shot()
{
	ABaseCharacter* CharacterOwner = StaticCast<ABaseCharacter*>(GetOwner());
	AController* Controller = CharacterOwner->GetController<APlayerController>();
	if (!IsValid(Controller))
	{
		return;
	}

	FVector PlayerViewPoint;
	FRotator PlayerViewRotation;
	Controller->GetPlayerViewPoint(PlayerViewPoint, PlayerViewRotation);
	FVector ViewDirection = PlayerViewRotation.RotateVector(FVector::ForwardVector);
	WeaponBarell->Shot(PlayerViewPoint, ViewDirection, Controller);
}

