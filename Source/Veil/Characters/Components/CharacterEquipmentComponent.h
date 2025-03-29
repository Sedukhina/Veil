// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Actors/Equipment/EquipableItem.h>
#include "CharacterEquipmentComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VEIL_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterEquipmentComponent();

	void CreateCurrentWeapon();
	void Attack();

	EEquipableItemType GetCurrentEquippedItemType();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	class AEquipableItem* CurrentEquippedItem;

	TSubclassOf<AEquipableItem> EquippedItemClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AEquipableItem> DefaultEquippedItemClass;

	TWeakObjectPtr<class ABaseCharacter> CachedOwner;
};
