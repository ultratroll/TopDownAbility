// Fill out your copyright notice in the Description page of Project Settings.


#include "TD_AttributeSet.h"
#include "GameplayEffectTypes.h"
#include "GameplayEffectExtension.h"
#include <UObject/ObjectMacros.h>


UTD_AttributeSet::UTD_AttributeSet()
	: Health(200.0f) , Mana(100.0f)
{
}

//------------------------------------------------------------------------------------------
void UTD_AttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UTD_AttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UTD_AttributeSet, Health)))
	{
		UE_LOG(LogTemp, Warning, TEXT("Health modified by a gameplay effect: %f"), Health.GetCurrentValue());
	}
}
