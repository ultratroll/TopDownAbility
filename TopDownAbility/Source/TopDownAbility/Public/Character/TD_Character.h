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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

};
