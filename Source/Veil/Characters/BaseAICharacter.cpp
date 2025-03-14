// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAICharacter.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"

ABaseAICharacter::ABaseAICharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void ABaseAICharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AAIController* NewAIController = Cast<AAIController>(NewController);
	if (IsValid(NewAIController))
	{
		NewAIController->SetGenericTeamId((uint8)Faction);
	}
}

UBehaviorTree* ABaseAICharacter::GetBehaviorTree() const
{
	return BehaviorTree;
}


