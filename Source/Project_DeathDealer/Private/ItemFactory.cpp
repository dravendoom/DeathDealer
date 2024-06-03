#include "ItemFactory.h"

UItemFactory::UItemFactory()
{
    // Constructor logic, if needed
}

void UItemFactory::LoadItemData(UDataTable* DataTable)
{
    if (!DataTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid DataTable."));
        return;
    }

    static const FString ContextString(TEXT("Item Data Context"));
    TArray<FItemDataStruct*> Rows;
    DataTable->GetAllRows(ContextString, Rows);

    for (auto& Row : Rows)
    {
        if (Row)
        {
            ItemDataMap.Add(Row->ItemName, *Row);
        }
    }
}

FItemDataStruct UItemFactory::GetItemByName(const FString& ItemName)
{
    if (ItemDataMap.Contains(ItemName))
    {
        return *ItemDataMap.Find(ItemName);
    }

    UE_LOG(LogTemp, Warning, TEXT("Item not found: %s"), *ItemName);
    return FItemDataStruct();
}
