// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VeilTypes.h"
#include "EquipableItem.generated.h"


UCLASS(Abstract, NotBlueprintable)
class VEIL_API AEquipableItem : public AActor
{
	GENERATED_BODY()
	
public:
	EEquipableItemType GetItemType() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EEquipableItemType ItemType = EEquipableItemType::None;
};
