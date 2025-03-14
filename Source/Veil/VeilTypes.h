#pragma once

const FName BB_Target = FName("Target");

UENUM(BlueprintType)
enum class EFactions : uint8
{
	Player UMETA(DisplayName = "Player"),
	Enemy UMETA(DisplayName = "Enemy")
};