// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "TD_AttributeSet.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTD_OnAttributeChanged, float, Value, float, MaxValue);

/**
 * 
 */
UCLASS()
class TOPDOWNABILITY_API UTD_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UTD_AttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delegate")
	FTD_OnAttributeChanged OnHealthChangedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delegate")
	FTD_OnAttributeChanged OnManaChangedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delegate")
	FTD_OnAttributeChanged OnStrenghtChangedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Base")
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData MaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData Strenght;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData MaxStrenght;

	/** Called after gameplay effect is applied. */
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data);
};
