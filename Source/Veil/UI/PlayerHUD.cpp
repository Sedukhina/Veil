// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerHUD.h"

#include "../Characters/BasePlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

#include "../Characters/Components/StatsComponent.h"
#include "../Characters/Components/PlayerComponents/MinimapCaptureComponent.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "Components/SceneCaptureComponent2D.h"
#include "Engine/SceneCapture2D.h"
#include "Engine/TextureRenderTarget2D.h"

#include "Components/Image.h"

void UPlayerHUD::NativeConstruct()
{
	Super::NativeConstruct();

	CachedPlayerCharacter = StaticCast<ABasePlayerCharacter*>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	CachedPlayerCharacter->GetMinimapCapture()->TextureTarget = MinimapRenderTarget;
	MinimapImageWidget->SetBrushSize(FVector2D(MinimapRenderTarget->SizeX, MinimapRenderTarget->SizeY));
	MinimapImageWidget->SetBrushFromMaterial(MinimapMaterial);
}

void UPlayerHUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	UStatsComponent* PlayerStats = CachedPlayerCharacter->GetStatsComponent();
	HealthBar->SetPercent(PlayerStats->GetCurrentHealthPercent());

	int CurrentHealth = PlayerStats->GetCurrentHealth();
	CurrentHealthTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d"), CurrentHealth)));

}
