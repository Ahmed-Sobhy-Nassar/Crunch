// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CCharacter.generated.h"

/**
 * ACCharacter - Base character class for the Crunch project.
 * Extends ACharacter to provide a common foundation for all characters.
 * Disables mesh collision by default for animation-driven characters.
 */
UCLASS()
class ACCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACCharacter();

	

protected:
	// Called when the game starts or when spawned into the world
	virtual void BeginPlay() override;

public:	
	// Called every frame to update character logic
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input (legacy input system)
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



#pragma region GAS

public:

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	// Ability system component for handling abilities and attributes
	UPROPERTY()
	class UCAbilitySystemComponent* CAbilitySystemComponent;
	// Attribute set for managing character attributes (health, stamina, etc.)
	UPROPERTY()
	class UCAttributeSet* CAttributeSet;


#pragma endregion

};
