// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "VeilAIController.generated.h"


class ABaseAICharacter;
/**
 * 
 */
UCLASS()
class VEIL_API AVeilAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	AVeilAIController();

	virtual void SetPawn(APawn* InPawn) override;
	virtual void ActorsPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UAIPerceptionComponent* AIPerception;

	TWeakObjectPtr<ABaseAICharacter> CachedPossesedCharacter;
};
