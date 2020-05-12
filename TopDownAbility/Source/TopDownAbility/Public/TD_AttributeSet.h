// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "TD_AttributeSet.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTD_OnHealthChanged, float, Health, float, MaxHealth);

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
	FTD_OnHealthChanged OnHealthChangedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Base")
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData MaxMana;

	/** Called after gameplay effect is applied. */
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data);
};
