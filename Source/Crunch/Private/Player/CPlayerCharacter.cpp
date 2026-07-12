// Fill out your copyright notice in the Description page of Project Settings.


// Include the player character header
#include "Player/CPlayerCharacter.h"
// Redundant include of own header (already included above)
#include "CPlayerCharacter.h"
// Camera component for third-person view
#include "Camera/CameraComponent.h"
// Enhanced Input subsystem for managing input mapping contexts
#include "EnhancedInputSubsystems.h"
// Enhanced Input component for binding input actions
#include "EnhancedInputComponent.h"
// Character movement component for locomotion and rotation settings
#include"GameFramework/CharacterMovementComponent.h"
// Spring arm component for camera boom (lag, collision avoidance)
#include "GameFramework/SpringArmComponent.h"
// Player controller for accessing the Enhanced Input subsystem
#include "GameFramework/PlayerController.h"

// Constructor: initializes camera components and movement behavior
ACPlayerCharacter::ACPlayerCharacter()
{

	// Create the spring arm (camera boom) and attach it to the root component
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	// Allow the spring arm to rotate with the controller (mouse/right stick)
	CameraBoom->bUsePawnControlRotation = true;
	// Create the camera and attach it to the end of the spring arm
	ViewCam = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCam"));
	ViewCam->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Disable controller rotation on pitch so the character doesn't tilt with the camera
	bUseControllerRotationPitch = false;	

	// Enable orient-to-movement: character rotates to face the direction of travel
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// Set rotation speed for orient-to-movement (degrees per second around Y-axis)
	GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);
}

// Called when the pawn is restarted (e.g., respawn or re-possession)
// Re-registers the input mapping context to ensure inputs are active
void ACPlayerCharacter::PawnClientRestart()
{
	// Call parent class restart logic
	Super::PawnClientRestart();
	// Get the owning player controller to access the Enhanced Input subsystem
	APlayerController* OwnigPlayerController = Cast<APlayerController>(GetController());
	if(OwnigPlayerController)
	{
		// Get the Enhanced Input subsystem from the local player
		UEnhancedInputLocalPlayerSubsystem* InputSubsystem = OwnigPlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		if(InputSubsystem)
		{
			// Remove then re-add the mapping context to avoid duplicates
			InputSubsystem->RemoveMappingContext(GameplayInputMappingContext);
			InputSubsystem->AddMappingContext(GameplayInputMappingContext, 0);
		}
	}
}

// Sets up Enhanced Input bindings for jump, look, and move actions
void ACPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Call parent class to set up default input bindings
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Cast to Enhanced Input component to use BindAction with Enhanced Input
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		// Bind jump action to the character's built-in Jump function
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ACPlayerCharacter::Jump);
		// Bind look action to the custom look handler
		EnhancedInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &ACPlayerCharacter::HandelLookInputAction);
		// Bind move action to the custom movement handler
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ACPlayerCharacter::HandelMoveInputAction);
	}

}

// Handles camera look input by converting 2D axis values to controller rotation
void ACPlayerCharacter::HandelLookInputAction(const FInputActionValue& InputActionValue)
{
	// Extract the 2D look axis (X = yaw, Y = pitch)
	FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	// Apply pitch (inverted for natural mouse look) and yaw to the controller
	AddControllerPitchInput(-LookAxisVector.Y);
	AddControllerYawInput(LookAxisVector.X);

}

// Handles character movement input with camera-relative direction
void ACPlayerCharacter::HandelMoveInputAction(const FInputActionValue& InputActionValue)
{
	// Extract the 2D move axis (X = strafe, Y = forward/back)
	FVector2D MoveAxisVector = InputActionValue.Get<FVector2D>();
	// Normalize to prevent faster diagonal movement
	MoveAxisVector.Normalize();
	// Calculate movement direction relative to camera orientation and apply to character
	AddMovementInput(GetLookForwardDir() * MoveAxisVector.Y + GetLookRigthDir() * MoveAxisVector.X);
}

// Returns the camera's right vector for strafing movement direction
FVector ACPlayerCharacter::GetLookRigthDir()
{
	return ViewCam->GetRightVector();

}

// Returns the camera's forward vector for forward/backward movement direction
FVector ACPlayerCharacter::GetLookForwardDir()
{
	return ViewCam->GetForwardVector();
}

// Returns the forward direction relative to the camera's right axis
// Uses cross product of right vector and world up to get a flat forward direction
FVector ACPlayerCharacter::GetMoveForwardDir()
{
	return FVector::CrossProduct(GetLookRigthDir(), FVector::UpVector);
}
