#pragma once

#define ECC_Projectile ECC_GameTraceChannel1

const FName BB_Target = FName("Target");

const FName CharacterRightArmItemSocket = FName("RightArmItemSocket");
const FName WeaponMuzzleSocket = FName("MuzzleSocket");

UENUM(BlueprintType)
enum class EEquipableItemType : uint8
{
	None,
	Pistol
};

UENUM(BlueprintType)
enum class EFactions : uint8
{
	Player UMETA(DisplayName = "Player"),
	Enemy UMETA(DisplayName = "Enemy")
};