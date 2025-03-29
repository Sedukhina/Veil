// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Characters/Components/BaseCharacterMovementComponent.h"
#include "Components/PlayerComponents/MinimapCaptureComponent.h"

ABasePlayerCharacter::ABasePlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->AttachToComponent(CameraBoom, FAttachmentTransformRules::KeepRelativeTransform);
	FollowCamera->bUsePawnControlRotation = false;
	FollowCamera->SetRelativeLocation(FVector(0.f, 0.f, 100.f));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	MinimapCameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Minimap Camera Boom"));
	MinimapCameraBoom->SetupAttachment(RootComponent);
	MinimapCameraBoom->TargetArmLength = 0.0f;
	MinimapCameraBoom->bUsePawnControlRotation = true;
	MinimapCameraBoom->bInheritPitch = false;
	MinimapCameraBoom->bInheritRoll = false;
	MinimapCameraBoom->bInheritYaw = true;

	MinimapCapture = CreateDefaultSubobject<UMinimapCaptureComponent>(TEXT("Minimap Capture"));
	MinimapCapture->AttachToComponent(MinimapCameraBoom, FAttachmentTransformRules::KeepRelativeTransform);
	MinimapCapture->SetRelativeLocation(FVector(0.f, 0.f, 500.f));

	Faction = EFactions::Player;
}

void ABasePlayerCharacter::Look(const FVector2D& Value)
{
	if (Controller)
	{
		AddControllerYawInput(Value.X);
		AddControllerPitchInput(Value.Y);
	}
}

void ABasePlayerCharacter::Move(const FVector2D& Value)
{
	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotationMatrix YawRotationMatrix(FRotator(0, Rotation.Yaw, 0));

		AddMovementInput(YawRotationMatrix.GetUnitAxis(EAxis::X), Value.Y);
		AddMovementInput(YawRotationMatrix.GetUnitAxis(EAxis::Y), Value.X);
	}
}

FGenericTeamId ABasePlayerCharacter::GetGenericTeamId() const
{
	return (uint8)Faction;
}

UMinimapCaptureComponent* ABasePlayerCharacter::GetMinimapCapture()
{
	return MinimapCapture;
}

void ABasePlayerCharacter::EquipCurrentWeapon()
{
	Super::EquipCurrentWeapon();

	CameraBoom->bUsePawnControlRotation = true;
	BaseCharacterMovementComponent->bOrientRotationToMovement = false;
	bUseControllerRotationYaw = true;

	CameraBoom->TargetOffset = FVector(0, 150, 0);
}
