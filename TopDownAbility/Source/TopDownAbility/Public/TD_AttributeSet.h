// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "TD_AttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWNABILITY_API UTD_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UTD_AttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Base")
	FGameplayAttributeData Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FGameplayAttributeData Mana;

	/** Called after gameplay effect is applied. */
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data);
};
