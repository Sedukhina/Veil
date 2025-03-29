// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Equipment/EquipableItem.h"
#include "EquipableItem.h"

EEquipableItemType AEquipableItem::GetItemType() const
{
	return ItemType;
}
