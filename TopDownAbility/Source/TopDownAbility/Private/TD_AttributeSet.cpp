// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_AttributeSet.h"
#include "GameplayEffectTypes.h"
#include "GameplayEffectExtension.h"
#include <UObject/ObjectMacros.h>

//------------------------------------------------------------------------------------------
UTD_AttributeSet::UTD_AttributeSet()
	: Health(200.0f), MaxHealth(200.0f), Mana(100.0f), MaxMana(100.0f), Strenght(200.0f), MaxStrenght(200.0f)
{
}

//------------------------------------------------------------------------------------------
void UTD_AttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UTD_AttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UTD_AttributeSet, Health)))
	{
		// Clamp health value
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), .0f, MaxHealth.GetBaseValue()));

		UE_LOG(LogTemp, Warning, TEXT("Health modified by a gameplay effect: %f"), Health.GetCurrentValue());

		OnHealthChangedDelegate.Broadcast(Health.GetCurrentValue(), MaxHealth.GetBaseValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UTD_AttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UTD_AttributeSet, Mana)))
	{
		// Clamp health value
		Mana.SetCurrentValue(FMath::Clamp(Mana.GetCurrentValue(), .0f, MaxMana.GetBaseValue()));

		UE_LOG(LogTemp, Warning, TEXT("Mana modified by a gameplay effect: %f"), Mana.GetCurrentValue());

		OnManaChangedDelegate.Broadcast(Mana.GetCurrentValue(), MaxMana.GetBaseValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UTD_AttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UTD_AttributeSet, Strenght)))
	{
		// Clamp Strenght value
		Strenght.SetCurrentValue(FMath::Clamp(Strenght.GetCurrentValue(), .0f, MaxStrenght.GetBaseValue()));

		UE_LOG(LogTemp, Warning, TEXT("Strenght modified by a gameplay effect: %f"), Strenght.GetCurrentValue());

		OnStrenghtChangedDelegate.Broadcast(Strenght.GetCurrentValue(), MaxStrenght.GetBaseValue());
	}
}
