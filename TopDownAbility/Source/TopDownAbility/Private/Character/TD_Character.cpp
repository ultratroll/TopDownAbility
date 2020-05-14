// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/TD_Character.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemComponent.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/Abilities/GameplayAbility.h"
#include "TD_AttributeSet.h"
#include <AIController.h>
#include "BrainComponent.h"

//------------------------------------------------------------------------------------------
ATD_Character::ATD_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilityComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilityComponent");

	AttributeSet = CreateDefaultSubobject<UTD_AttributeSet>("UTD_AttributeSet");

	AttributeSet->OnHealthChangedDelegate.AddDynamic(this, &ATD_Character::OnHealthChanged);

	Team = 255;
}

//------------------------------------------------------------------------------------------
void ATD_Character::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetController() && GetController()->IsPlayerController())
		Team = 0;
}

//------------------------------------------------------------------------------------------
void ATD_Character::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	AttributeSet->OnHealthChangedDelegate.RemoveAll(this);
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

//------------------------------------------------------------------------------------------
void ATD_Character::OnHealthChanged(float Health, float MaxHealth)
{
	if (Health <= 0 && !bIsDead)
	{
		bIsDead = true;
		DisableController();
		BP_OnDeath();
	}

	BP_OnHealthChanged(Health, MaxHealth);
}

//------------------------------------------------------------------------------------------
uint8 ATD_Character::GetTeam()
{
	return Team;
}

//------------------------------------------------------------------------------------------
bool ATD_Character::IsHostile(ATD_Character* OtherCharacter)
{
	return OtherCharacter->GetTeam() != Team;
}

//------------------------------------------------------------------------------------------
void ATD_Character::DisableController()
{
	APlayerController* MyPC = Cast<APlayerController>(GetController());
	if (MyPC)
	{
		MyPC->DisableInput(MyPC);
	}

	AAIController* AIC = Cast<AAIController>(GetController());
	if (AIC)
	{
		AIC->GetBrainComponent()->StopLogic("Dead");
	}

}


