#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryStruct.h"
#include "ItemDataStruct.h"
#include "Inventory.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryFullDelegate, const FItemDataStruct&, Item);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECT_DEATHDEALER_API UInventory : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventory();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddItem(const FItemDataStruct& Item);

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void RemoveItem(const FItemDataStruct& Item);

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void ReplaceItem(int32 Index, const FItemDataStruct& Item);

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    ERarity PickRarity() const;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    ENormalItem PickNormalItem() const;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    EMagicItem PickMagicItem() const;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    ERareItem PickRareItem() const;

    UFUNCTION(BlueprintCallable, Category = "Inventory")
    ELegendaryItem PickLegendaryItem() const;

    UPROPERTY(BlueprintAssignable, Category = "Inventory")
    FOnInventoryFullDelegate OnInventoryFull;

private:
    UPROPERTY(VisibleAnywhere, Category = "Inventory")
    TArray<FItemDataStruct> Items;

    UPROPERTY(EditAnywhere, Category = "Inventory")
    int32 MaxItems;

    UPROPERTY(EditAnywhere, Category = "Inventory")
    TArray<FRarity> RarityWeights;

    UPROPERTY(EditAnywhere, Category = "Inventory")
    TArray<FNormalItem> NormalItemWeights;

    UPROPERTY(EditAnywhere, Category = "Inventory")
    TArray<FMagicItem> MagicItemWeights;

    UPROPERTY(EditAnywhere, Category = "Inventory")
    TArray<FRareItem> RareItemWeights;

    UPROPERTY(EditAnywhere, Category = "Inventory")
    TArray<FLegendaryItem> LegendaryItemWeights;
    
   
};
