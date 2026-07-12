// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Core minimal types (FVector, FString, etc.)
#include "CoreMinimal.h"
// Base character class with skeletal mesh, movement, and collision support
#include "GameFramework/Character.h"
// Generated header for Unreal reflection and serialization
#include "CCharacter.generated.h"

/**
 * ACCharacter - Base character class for the Crunch project.
 * Extends ACharacter to provide a common foundation for all characters.
 * Disables mesh collision by default for animation-driven characters.
 */
UCLASS()
class ACCharacter : public ACharacter
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

};
