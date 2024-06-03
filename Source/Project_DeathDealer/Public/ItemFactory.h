#pragma once

#include "CoreMinimal.h"
#include "ItemDataStruct.h"
#include "Engine/DataTable.h"
#include "ItemFactory.generated.h"

UCLASS()
class PROJECT_DEATHDEALER_API UItemFactory : public UObject
{
    GENERATED_BODY()

public:
    UItemFactory();

    UFUNCTION(BlueprintCallable, Category = "ItemFactory")
    void LoadItemData(UDataTable* DataTable);

    UFUNCTION(BlueprintCallable, Category = "ItemFactory")
    FItemDataStruct GetItemByName(const FString& ItemName);

private:
    TMap<FString, FItemDataStruct> ItemDataMap;
};
