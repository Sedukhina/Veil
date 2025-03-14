// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilAIController.h"

#include "Perception/AIPerceptionComponent.h"

#include "Veil/Characters/BaseAICharacter.h"
#include <BehaviorTree/BlackboardComponent.h>


AVeilAIController::AVeilAIController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception"));
}

void AVeilAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (IsValid(InPawn))
	{
		checkf(InPawn->IsA<ABaseAICharacter>(), TEXT("AVeilAIController::SetPawn AVeilAIController can possess only BaseAICharacter"));
		CachedPossesedCharacter = StaticCast<ABaseAICharacter*>(InPawn);
		RunBehaviorTree(CachedPossesedCharacter->GetBehaviorTree());
	}
}

void AVeilAIController::ActorsPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	Super::ActorsPerceptionUpdated(UpdatedActors);

	GEngine->AddOnScreenDebugMessage(4, 10.0f, FColor::Emerald, "AVeilAIController::ActorsPerceptionUpdated");
	if (UpdatedActors[0] && Blackboard)
	{
		FString Str;
		UpdatedActors[0]->GetName(Str);
		GEngine->AddOnScreenDebugMessage(0, 2.0f, FColor::Emerald, Str);
		Blackboard->SetValueAsObject(BB_Target, UpdatedActors[0]);
	}
}

