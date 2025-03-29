// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"

#include "Characters/Components/BaseCharacterMovementComponent.h"

#include "Characters/Components/StatsComponent.h"
#include "Characters/Components/CharacterEquipmentComponent.h"

#include "Engine/DamageEvents.h"

// Sets default values
ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UBaseCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseCharacterMovementComponent = StaticCast<UBaseCharacterMovementComponent*>(GetCharacterMovement());

	StatsComponent = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats"));
	StatsComponent->OnDeath.AddUObject(this, &ABaseCharacter::OnDeath);

	CharacterEquipmentComponent = CreateDefaultSubobject<UCharacterEquipmentComponent>(TEXT("Character Equipment"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UBaseCharacterMovementComponent* ABaseCharacter::GetBaseCharacterMovementComponent()
{
	return BaseCharacterMovementComponent;
}

UStatsComponent* ABaseCharacter::GetStatsComponent()
{
	return StatsComponent;
}

void ABaseCharacter::OnDeath(AActor* DeathCauser)
{
	GEngine->AddOnScreenDebugMessage(3, 10.f, FColor::Black, TEXT("I'M DEAD"));
	BaseCharacterMovementComponent->DisableMovement();
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionProfileName("Ragdoll");
}

void ABaseCharacter::Falling()
{
	Super::Falling();
	FallingApex = GetActorLocation();
}

void ABaseCharacter::NotifyJumpApex()
{
	Super::NotifyJumpApex();
	FallingApex = GetActorLocation();
}

void ABaseCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	if (IsValid(FallDamageCurve))
	{
		float FallDamage = FallDamageCurve->GetFloatValue(FallingApex.Z - GetActorLocation().Z);
		GEngine->AddOnScreenDebugMessage(0, 2.0f, FColor::Emerald, FString::Printf(TEXT("FallDamage %f"), FallDamage));
		TakeDamage(FallDamage, FDamageEvent(), GetController(), Hit.GetActor());
	}
}

void ABaseCharacter::EquipCurrentWeapon()
{
	CharacterEquipmentComponent->CreateCurrentWeapon();
}

void ABaseCharacter::Attack()
{
	CharacterEquipmentComponent->Attack();
}

EEquipableItemType ABaseCharacter::GetCurrentEquippedItemType()
{
	return CharacterEquipmentComponent->GetCurrentEquippedItemType();
}
