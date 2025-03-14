// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilPlayerController.h"
#include "Characters/BasePlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AVeilPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}

	CachedCharacter = Cast<ABasePlayerCharacter>(GetPawn());
}

void AVeilPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Checkimg if current input is enhanced input component 
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Binding actions to input
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVeilPlayerController::Move);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AVeilPlayerController::Jump);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVeilPlayerController::Look);
	}
}

void AVeilPlayerController::Move(const FInputActionValue& Value)
{
	if (CachedCharacter.IsValid())
	{
		// Converting values so input system is completely separated from character
		FVector2D MovementInputVector = Value.Get<FVector2D>();
		CachedCharacter->Move(MovementInputVector);
	}
}

void AVeilPlayerController::Jump()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Jump();
	}
}

void AVeilPlayerController::Look(const FInputActionValue& Value)
{
	if (CachedCharacter.IsValid())
	{
		// Converting values so input system is completely separated from character
		FVector2D CameraMovementInputVector = Value.Get<FVector2D>();
		CachedCharacter->Look(CameraMovementInputVector);
	}
}
