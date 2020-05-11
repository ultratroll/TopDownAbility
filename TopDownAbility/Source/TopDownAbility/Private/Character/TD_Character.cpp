// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/TD_Character.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemComponent.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/Abilities/GameplayAbility.h"

//------------------------------------------------------------------------------------------
ATD_Character::ATD_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilityComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilityComponent");
}

//------------------------------------------------------------------------------------------
void ATD_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

//------------------------------------------------------------------------------------------
void ATD_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//------------------------------------------------------------------------------------------
void ATD_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//------------------------------------------------------------------------------------------
UAbilitySystemComponent* ATD_Character::GetAbilitySystemComponent() const
{
	return AbilityComponent;
}

//------------------------------------------------------------------------------------------
void ATD_Character::AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire)
{
	if (AbilityComponent)
	{
		if (HasAuthority() && AbilityToAquire)
		{
			FGameplayAbilitySpecDef SpecsDef= FGameplayAbilitySpecDef();
			SpecsDef.Ability = AbilityToAquire;

			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(SpecsDef,1);

			AbilityComponent->GiveAbility(AbilitySpec);

			AbilityComponent->InitAbilityActorInfo(this, this);
		}
	}
}

