// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponBarellComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VEIL_API UWeaponBarellComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponBarellComponent();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UCurveFloat* DamageCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float FiringRange = 100.f;

public:	
	void Shot(FVector ShotStart, FVector ShotDirection, AController* Controller);
		
};
