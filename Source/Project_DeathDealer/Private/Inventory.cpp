#include "Inventory.h"

UInventory::UInventory()
{
    PrimaryComponentTick.bCanEverTick = false;
    MaxItems = 6;

    RarityWeights.Add(FRarity{ ERarity::NoDrop, 100000 });
    RarityWeights.Add(FRarity{ ERarity::Normal, 10000 });
    RarityWeights.Add(FRarity{ ERarity::Magic, 1000 });
    RarityWeights.Add(FRarity{ ERarity::Rare, 500 });
    RarityWeights.Add(FRarity{ ERarity::Legendary, 100 });

    NormalItemWeights.Add(FNormalItem{ ENormalItem::ShortSword, 1000000 });
    NormalItemWeights.Add(FNormalItem{ ENormalItem::WeakStaff, 100 });
    NormalItemWeights.Add(FNormalItem{ ENormalItem::RingOfVigor, 100 });
    NormalItemWeights.Add(FNormalItem{ ENormalItem::SilverSignet, 100 });
    NormalItemWeights.Add(FNormalItem{ ENormalItem::Cap, 100 });

    MagicItemWeights.Add(FMagicItem{ EMagicItem::CapOfCooldowns, 100 });
    MagicItemWeights.Add(FMagicItem{ EMagicItem::StaffOfSpeed, 100 });
    MagicItemWeights.Add(FMagicItem{ EMagicItem::BootsOfSwiftness, 100 });
    MagicItemWeights.Add(FMagicItem{ EMagicItem::GiantGauntlets, 100 });

    RareItemWeights.Add(FRareItem{ ERareItem::FullHelmOfTheFigher, 100 });
    RareItemWeights.Add(FRareItem{ ERareItem::SilverStingerOfBravos, 100 });
    RareItemWeights.Add(FRareItem{ ERareItem::RingOfRegha, 100 });

    LegendaryItemWeights.Add(FLegendaryItem{ ELegendaryItem::BrotherLazarus, 100 });
    LegendaryItemWeights.Add(FLegendaryItem{ ELegendaryItem::DeathAndTaxes, 100 });
}

void UInventory::BeginPlay()
{
    Super::BeginPlay();
}

void UInventory::AddItem(const FItemDataStruct& Item)
{
    if (Items.Num() < MaxItems)
    {
        Items.Add(Item);
    }
    else
    {
        OnInventoryFull.Broadcast(Item);
    }
}

void UInventory::RemoveItem(const FItemDataStruct& Item)
{
    Items.Remove(Item);
}

void UInventory::ReplaceItem(int32 Index, const FItemDataStruct& NewItem)
{
    if (Items.IsValidIndex(Index))
    {
        Items[Index] = NewItem;
    }
}

ERarity UInventory::PickRarity() const
{
    int32 totalWeight = 0;
    for (const FRarity& Rarity : RarityWeights) {
        totalWeight += Rarity.Weight;
    }

    int32 randomWeight = FMath::RandRange(1, totalWeight);

    int32 currentWeight = 0;
    for (const FRarity& Rarity : RarityWeights)
    {
        currentWeight += Rarity.Weight;
        if (randomWeight <= currentWeight) {
            return Rarity.RarityType;
        }
    }

    return ERarity::NoDrop;

}

ENormalItem UInventory::PickNormalItem() const
{
    int32 totalWeight = 0;
    for (const FNormalItem& Item : NormalItemWeights) {
        totalWeight += Item.Weight;
    }

    int32 randomWeight = FMath::RandRange(1, totalWeight);

    int32 currentWeight = 0;
    for (const FNormalItem& Item : NormalItemWeights)
    {
        currentWeight += Item.Weight;
        if (randomWeight <= currentWeight) {
            return Item.Item;
        }
    }

    return ENormalItem::Cap;


}

EMagicItem UInventory::PickMagicItem() const
{
    int32 totalWeight = 0;
    for (const FMagicItem& Item : MagicItemWeights) {
        totalWeight += Item.Weight;
    }

    int32 randomWeight = FMath::RandRange(1, totalWeight);

    int32 currentWeight = 0;
    for (const FMagicItem& Item : MagicItemWeights)
    {
        currentWeight += Item.Weight;
        if (randomWeight <= currentWeight) {
            return Item.Item;
        }
    }

    return EMagicItem::BootsOfSwiftness;

}

ERareItem UInventory::PickRareItem() const
{
    int32 totalWeight = 0;
    for (const FRareItem& Item : RareItemWeights) {
        totalWeight += Item.Weight;
    }

    int32 randomWeight = FMath::RandRange(1, totalWeight);

    int32 currentWeight = 0;
    for (const FRareItem& Item : RareItemWeights)
    {
        currentWeight += Item.Weight;
        if (randomWeight <= currentWeight) {
            return Item.Item;
        }
    }

    return ERareItem::FullHelmOfTheFigher;

}

ELegendaryItem UInventory::PickLegendaryItem() const
{
    int32 totalWeight = 0;
    for (const FLegendaryItem& Item : LegendaryItemWeights) {
        totalWeight += Item.Weight;
    }

    int32 randomWeight = FMath::RandRange(1, totalWeight);

    int32 currentWeight = 0;
    for (const FLegendaryItem& Item : LegendaryItemWeights)
    {
        currentWeight += Item.Weight;
        if (randomWeight <= currentWeight) {
            return Item.Item;
        }
    }

    return ELegendaryItem::BrotherLazarus;

}


