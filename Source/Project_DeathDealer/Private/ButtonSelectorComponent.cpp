#include "ButtonSelectorComponent.h"
#include "Engine/Engine.h"

UButtonSelectorComponent::UButtonSelectorComponent()
{
	SpellButtons.Add(FButtonSelector(TEXT("FireBlast"), 50));
	SpellButtons.Add(FButtonSelector(TEXT("ChainLightning"), 50));
	SpellButtons.Add(FButtonSelector(TEXT("FlameFront"), 50));
	SpellButtons.Add(FButtonSelector(TEXT("Malice"), 50));
	SpellButtons.Add(FButtonSelector(TEXT("BoneRipple"), 50));

	PassiveButtons.Add(FButtonSelector(TEXT("Chain"), 20));
	PassiveButtons.Add(FButtonSelector(TEXT("Projectiles"), 20));
	PassiveButtons.Add(FButtonSelector(TEXT("Health"), 50));
	PassiveButtons.Add(FButtonSelector(TEXT("Dam"), 50));
	PassiveButtons.Add(FButtonSelector(TEXT("Movement"), 50));
	PassiveButtons.Add(FButtonSelector(TEXT("CD"), 50));
}

FButtonSelector UButtonSelectorComponent::PickSpellButton()
{
	int32 TotalWeight = 0;
	for (FButtonSelector& Button : SpellButtons)
	{
		TotalWeight += Button.Weight;
	}

	int32 RandomWeight = FMath::RandRange(1, TotalWeight);

	int32 CurrentWeight = 0;
	for (FButtonSelector& Button : SpellButtons)
	{
		CurrentWeight += Button.Weight;
		if (RandomWeight <= CurrentWeight)
		{
			ReduceButtonWeight(Button.ButtonName, 10, SpellButtons);
			return Button;
		}
	}

	return FButtonSelector();
}

FButtonSelector UButtonSelectorComponent::PickPassiveButton()
{
	int32 TotalWeight = 0;
	for (FButtonSelector& Button : PassiveButtons)
	{
		TotalWeight += Button.Weight;
	}

	int32 RandomWeight = FMath::RandRange(1, TotalWeight);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("RandomWeight: %d"), RandomWeight));

	int32 CurrentWeight = 0;
	for (FButtonSelector& Button : PassiveButtons)
	{
		CurrentWeight += Button.Weight;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("CurrentWeight: %d, ButtonName: %s, ButtonWeight: %d"), CurrentWeight, *Button.ButtonName, Button.Weight));
		if (RandomWeight <= CurrentWeight)
		{
			ReduceButtonWeight(Button.ButtonName, 10, PassiveButtons);
			return Button;
		}
	}

	return FButtonSelector();
}

void UButtonSelectorComponent::ReduceButtonWeight(const FString& ButtonName, int32 Amount, TArray<FButtonSelector> ary)
{
	for (FButtonSelector& Button : SpellButtons)
	{
		if (Button.ButtonName == ButtonName)
		{
			Button.Weight = FMath::Max(0, Button.Weight - Amount); // Ensure weight doesn't go below 0
			break;
		}
	}
}
