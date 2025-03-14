// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "VeilPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VEIL_API AVeilPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	// Possesed base character ptr
	TWeakObjectPtr<class ABasePlayerCharacter> CachedCharacter;

	// Input Mapping
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputMappingContext* MappingContext;

	// Input Actions 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* JumpAction;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* LookAction;

	// Character functions
	void Move(const FInputActionValue& Value);
	void Jump();

	void Look(const FInputActionValue& Value);
};
