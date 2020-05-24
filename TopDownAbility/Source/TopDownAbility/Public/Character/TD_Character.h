// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Plugins/Runtime/GameplayAbilities/Source/GameplayAbilities/Public/AbilitySystemInterface.h"
#include "TD_Character.generated.h"

class UAbilitySystemComponent;
class UGameplayAbility;
class UTD_AttributeSet;

UCLASS()
class TOPDOWNABILITY_API ATD_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATD_Character();

	virtual void PossessedBy(AController* NewController) override;

protected:

	UPROPERTY()
	bool bIsDead;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when the game starts or when spawned
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UPROPERTY(BlueprintReadWrite, Category = "Abilities")
	UAbilitySystemComponent* AbilityComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Abilities")
	UTD_AttributeSet* AttributeSet;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire);

	UFUNCTION()
	void OnHealthChanged(float Health, float MaxHealth);

	UFUNCTION()
	void OnManaChanged(float Mana, float MaxMana);

	UFUNCTION()
	void OnStrenghtChanged(float Strenght, float MaxStrenght);

	UFUNCTION(BlueprintImplementableEvent, Category= "CharacterBase", meta= (DisplayName= "On Health Changed"))
	void BP_OnHealthChanged(float Health, float MaxHealth);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "On Mana Changed"))
	void BP_OnManaChanged(float Mana, float MaxMana);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "On Strenght Changed"))
	void BP_OnStrenghtChanged(float Strenght, float MaxStrenght);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "On Death"))
	void BP_OnDeath();

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	uint8 GetTeam();

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	bool IsHostile(ATD_Character* OtherCharacter);

private:

	uint8 Team;

	// To be used upon death
	void DisableController();

};
