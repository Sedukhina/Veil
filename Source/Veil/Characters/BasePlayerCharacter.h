// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"

#include "GenericTeamAgentInterface.h"

#include "BasePlayerCharacter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class VEIL_API ABasePlayerCharacter : public ABaseCharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

protected:

	// Player camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseCharacter|Camera")
	class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseCharacter|Camera")
	class USpringArmComponent* CameraBoom;

	// Minimap capture components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Minimap")
	class UMinimapCaptureComponent* MinimapCapture;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Minimap")
	class USpringArmComponent* MinimapCameraBoom;

public:
	ABasePlayerCharacter(const FObjectInitializer& ObjectInitializer);

	// Camera movement
	void Look(const FVector2D& Value);

	virtual FGenericTeamId GetGenericTeamId() const override;

	class UMinimapCaptureComponent* GetMinimapCapture();
};
