	// Fill out your copyright notice in the Description page of Project Settings.


// Include the base character header
#include "Player/CCharacter.h"

// Constructor: initializes default character properties
ACCharacter::ACCharacter()
{
 	// Enable Tick() to be called every frame for this character
	// Disable if not needed to improve performance
	PrimaryActorTick.bCanEverTick = true;

	// Disable collision on the skeletal mesh to prevent physics interference
	// with animation-driven characters
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned into the world
// Used for initialization that requires world context
void ACCharacter::BeginPlay()
{
	// Call parent class BeginPlay to ensure proper initialization chain
	Super::BeginPlay();
	
}

// Called every frame
// Used for per-frame character updates (animation, logic, etc.)
void ACCharacter::Tick(float DeltaTime)
{
	// Call parent class Tick to maintain the update chain
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
// Override this to set up custom input bindings for derived characters
void ACCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Call parent class to set up default input bindings
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
