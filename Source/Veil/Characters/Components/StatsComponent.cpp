// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsComponent.h"
#include "../BaseCharacter.h"

// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsAlive())
	{
		CurrentHealth += HealthRecoverySpeed * DeltaTime;
		CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);
	}
}

// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	CachedOwner = StaticCast<ABaseCharacter*>(GetOwner());
	CachedOwner->OnTakeAnyDamage.AddDynamic(this, &UStatsComponent::OnTakeAnyDamage);
}

float UStatsComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UStatsComponent::GetCurrentHealthPercent()
{
	return CurrentHealth/MaxHealth;
}

bool UStatsComponent::IsAlive()
{
	return CurrentHealth > 0 ? true : false;
}

void UStatsComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth -= Damage;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);

	if (CurrentHealth == 0)
	{
		OnDeath.Broadcast(DamageCauser);
	}
}

