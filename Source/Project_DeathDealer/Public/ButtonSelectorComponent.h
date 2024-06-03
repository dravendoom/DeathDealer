// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ButtonSelectorComponent.generated.h"

USTRUCT(BlueprintType)
struct FButtonSelector
{
	GENERATED_BODY()

	FButtonSelector() : ButtonName(TEXT("")), Weight(0) {}
	FButtonSelector(FString Name, int32 InWeight) : ButtonName(Name), Weight(InWeight) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSelector")
	FString ButtonName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSelector")
	int32 Weight;

};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_DEATHDEALER_API UButtonSelectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UButtonSelectorComponent();

public:	
	
	UPROPERTY(EditAnywhere, Category = "ButtonSelector")
	TArray<FButtonSelector> SpellButtons;

	UPROPERTY(EditAnywhere, Category = "ButtonSelector")
	TArray<FButtonSelector> PassiveButtons;

	UFUNCTION(BlueprintCallable, Category = "ButtonSelector")
	FButtonSelector PickSpellButton() ;

	UFUNCTION(BlueprintCallable, Category = "ButtonSelector")
	FButtonSelector PickPassiveButton();

	UFUNCTION(BlueprintCallable, Category = "ButtonSelector")
	void ReduceButtonWeight(const FString& ButtonName, int32 Amount, TArray<FButtonSelector> ary);


};



