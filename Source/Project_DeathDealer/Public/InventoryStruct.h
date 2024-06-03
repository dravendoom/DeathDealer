// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStruct.generated.h"

UENUM(BlueprintType)
enum class ERarity : uint8
{
	NoDrop		UMETA(DisplayName = "NoDrop"),
	Normal		UMETA(DisplayName = "Normal"),
	Magic		UMETA(DisplayName = "Magic"),
	Rare		UMETA(DisplayName = "Rare"),
	Legendary	UMETA(DisplayName = "Legendary")
};

UENUM(BlueprintType)
enum class ENormalItem : uint8
{
	ShortSword		UMETA(DisplayName = "Short Sword"),
	WeakStaff		UMETA(DisplayName = "Weak Staff"),
	RingOfVigor		UMETA(DisplayName = "Ring of Vigor"),
	SilverSignet	UMETA(DisplayName = "Silver Signet"),
	Cap				UMETA(DisplayName = "Cap")
};

UENUM(BlueprintType)
enum class EMagicItem : uint8
{
	CapOfCooldowns		UMETA(DisplayName = "Cap of Cooldowns"),
	StaffOfSpeed		UMETA(DisplayName = "Staff of Speeds"),
	BootsOfSwiftness	UMETA(DisplayName = "Boots of Swiftness"),
	GiantGauntlets		UMETA(DisplayName = "Giant Gauntlets")
};

UENUM(BlueprintType)
enum class ERareItem : uint8
{
	FullHelmOfTheFigher			UMETA(DisplayName = "Full Helm of the Fighter"),
	SilverStingerOfBravos		UMETA(DisplayName = "Silver Stinger of Bravos"),
	RingOfRegha					UMETA(DisplayName = "Ring of Regha")
};

UENUM(BlueprintType)
enum class ELegendaryItem : uint8
{
	BrotherLazarus		UMETA(DisplayName = "Brother Lazarus"),
	DeathAndTaxes		UMETA(DisplayName = "Death and Taxes"),
};

USTRUCT(BlueprintType)
struct FRarity
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	ERarity RarityType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	int32 Weight;

};

USTRUCT(BlueprintType)
struct FNormalItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	ENormalItem Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	int32 Weight;

};

USTRUCT(BlueprintType)
struct FMagicItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	EMagicItem Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	int32 Weight;

};

USTRUCT(BlueprintType)
struct FRareItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	ERareItem Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	int32 Weight;

};

USTRUCT(BlueprintType)
struct FLegendaryItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	ELegendaryItem Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rarity")
	int32 Weight;

};

