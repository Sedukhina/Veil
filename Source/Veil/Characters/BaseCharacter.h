// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "../VeilTypes.h"

#include "BaseCharacter.generated.h"

UCLASS(NotBlueprintable)
class VEIL_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Base character movement
	void Move(const FVector2D& Value);

	class UBaseCharacterMovementComponent* GetBaseCharacterMovementComponent();
	class UStatsComponent* GetStatsComponent();
		
	virtual void OnDeath(AActor* DeathCauser);

protected:

	// Custom Movement Component
	class UBaseCharacterMovementComponent* BaseCharacterMovementComponent;

	// Stats Component
	class UStatsComponent* StatsComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Faction")
	EFactions Faction = EFactions::Enemy;
};
