// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterEquipmentComponent.h"

#include "Characters/BaseCharacter.h"

#include "Actors/Equipment/EquipableItem.h"
#include <Actors/Equipment/Weapons/RangeWeapon.h>

UCharacterEquipmentComponent::UCharacterEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCharacterEquipmentComponent::CreateCurrentWeapon()
{
	if (IsValid(CurrentEquippedItem))
		return;
	CurrentEquippedItem = GetWorld()->SpawnActor<AEquipableItem>(EquippedItemClass);
	CurrentEquippedItem->AttachToComponent(CachedOwner->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, CharacterRightArmItemSocket);
	CurrentEquippedItem->SetOwner(CachedOwner.Get());
}

void UCharacterEquipmentComponent::Attack()
{
	if (IsValid(CurrentEquippedItem))
	{
		EEquipableItemType CurrentEquippedItemType = CurrentEquippedItem->GetItemType();
		if (CurrentEquippedItemType == EEquipableItemType::Pistol)
		{
			ARangeWeapon* Weapon = Cast<ARangeWeapon>(CurrentEquippedItem);
			Weapon->Shot();
		}
	}
}

EEquipableItemType UCharacterEquipmentComponent::GetCurrentEquippedItemType()
{
	if (IsValid(CurrentEquippedItem))
	{
		return CurrentEquippedItem->GetItemType();
	}
	return EEquipableItemType::None;
}

void UCharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	CachedOwner = StaticCast<ABaseCharacter*>(GetOwner());
	EquippedItemClass = DefaultEquippedItemClass;
}

