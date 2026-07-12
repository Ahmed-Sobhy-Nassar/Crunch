// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Core minimal types (FVector, FString, etc.)
#include "CoreMinimal.h"
// Base character class this player character inherits from
#include "Player/CCharacter.h"
// FInputActionValue type for Enhanced Input action callbacks
#include "InputActionValue.h"
// Generated header for Unreal reflection and serialization
#include "CPlayerCharacter.generated.h"

/**
 * ACPlayerCharacter - Player-controlled character class.
 * Extends ACCharacter with a spring-arm camera setup, Enhanced Input bindings,
 * and camera-relative movement. This is the main class the player controls.
 */
UCLASS()
class ACPlayerCharacter : public ACCharacter
{
	GENERATED_BODY()

public:

	// Constructor: sets up camera components and movement settings
	ACPlayerCharacter();

	// Called when the pawn is restarted (e.g., on respawn or possession)
	// Re-registers the input mapping context with the Enhanced Input system
	virtual void PawnClientRestart() override;
	// Binds Enhanced Input actions to character functions
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	// Spring arm component: provides camera lag and collision avoidance
	UPROPERTY(VisibleDefaultsOnly, Category = "View")
	class USpringArmComponent* CameraBoom;

	// Camera component: attached to the spring arm for third-person view
	UPROPERTY(VisibleDefaultsOnly, Category = "View")
	class UCameraComponent* ViewCam;

	// Input mapping context: defines which actions are available during gameplay
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* GameplayInputMappingContext;
	// Input action for jumping (spacebar by default)
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* JumpInputAction;

	// Input action for camera look (mouse/right stick)
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* LookInputAction;
	// Input action for character movement (WASD/left stick)
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* MoveInputAction;


	// Handles look input: converts 2D input to controller pitch/yaw rotation
	void HandelLookInputAction(const FInputActionValue& InputActionValue);
	// Handles movement input: converts 2D input to camera-relative movement
	void HandelMoveInputAction(const FInputActionValue& InputActionValue);
	
	// Returns the camera's right direction for strafing movement
	FVector GetLookRigthDir();
	// Returns the camera's forward direction for forward/backward movement
	FVector GetLookForwardDir();
	// Returns the forward direction relative to the camera's right axis (cross product with up)
	FVector GetMoveForwardDir();
};
