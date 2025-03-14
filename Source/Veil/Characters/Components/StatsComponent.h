// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnDeath, AActor*)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VEIL_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TWeakObjectPtr<class ABaseCharacter> CachedOwner;

	UPROPERTY(EditDefaultsOnly, Category = Health)
	float MaxHealth = 900;

	UPROPERTY(EditDefaultsOnly, Category = Health)
	float HealthRecoverySpeed = 2;

	float CurrentHealth;

public:	
	float GetCurrentHealth();
	float GetCurrentHealthPercent();
	// Returns health > 0
	bool IsAlive();

	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	FOnDeath OnDeath;
};
