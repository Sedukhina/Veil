// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacterAnimInstance.h"

#include "BaseCharacter.h"
#include "Components/BaseCharacterMovementComponent.h"

void UBaseCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	CachedOwner = StaticCast<ABaseCharacter*>(TryGetPawnOwner());
}

void UBaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (CachedOwner.IsValid())
	{
		UBaseCharacterMovementComponent* OwnerCharacterMovementComponent = CachedOwner->GetBaseCharacterMovementComponent();
		Speed = OwnerCharacterMovementComponent->Velocity.Size();
		bIsFalling = OwnerCharacterMovementComponent->IsFalling();
	}
}
