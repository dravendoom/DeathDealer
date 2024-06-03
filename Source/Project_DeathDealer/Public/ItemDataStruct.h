#pragma once

#include "CoreMinimal.h"
#include "ItemDataStruct.generated.h"

USTRUCT(BlueprintType)
struct PROJECT_DEATHDEALER_API FItemDataStruct : public FTableRowBase
{
    GENERATED_BODY()

public:
    FItemDataStruct()
        : ItemName(TEXT(""))
        , ItemRarity(TEXT(""))
        , ItemDescription(TEXT(""))
    {
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FString ItemRarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FString ItemDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    TMap<FName, float> Stats;

    bool operator==(const FItemDataStruct& Other) const
    {
        return ItemName == Other.ItemName &&
            ItemRarity == Other.ItemRarity &&
            ItemDescription == Other.ItemDescription &&
            Stats.OrderIndependentCompareEqual(Other.Stats);
    }
};

// No need for explicit destructor as the default is sufficient
