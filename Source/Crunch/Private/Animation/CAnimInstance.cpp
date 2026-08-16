// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/CAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
void UCAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if(OwnerCharacter)
	{
		OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
	}
}

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (OwnerCharacter)
	{
		Speed = OwnerCharacter->GetVelocity().Length();	

	}

	if(OwnerMovementComponent)
	{
		bIsJumping = OwnerMovementComponent->IsFalling();
	}
}

void UCAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
}


float UCAnimInstance::CalculateLeanAngle() const
{
	// Reuses the yaw turn-rate you already compute in NativeUpdateAnimation —
	// no need to re-derive a rotation delta here.
	return FMath::Clamp(SmoothedYawSpeed * LeanScale, -MaxLeanAngle, MaxLeanAngle);
}

float UCAnimInstance::CalculateSlopeAngle() const
{
	if (!OwnerCharacter)
	{
		return 0.f;
	}

	UCharacterMovementComponent* MovementComponent = OwnerCharacter->GetCharacterMovement();
	if (!MovementComponent || !MovementComponent->CurrentFloor.IsWalkableFloor())
	{
		return 0.f;
	}

	const FVector FloorNormal = MovementComponent->CurrentFloor.HitResult.ImpactNormal;
	const FVector Forward = OwnerCharacter->GetActorForwardVector();

	// Project forward onto the slope plane; the Z of the result is the signed pitch.
	FVector ForwardOnSlope = FVector::VectorPlaneProject(Forward, FloorNormal);
	if (!ForwardOnSlope.Normalize())
	{
		return 0.f; // Forward is parallel to the normal (shouldn't happen on walkable floor).
	}

	const float SlopeRadians = FMath::Asin(FMath::Clamp(ForwardOnSlope.Z, -1.f, 1.f));
	return FMath::RadiansToDegrees(SlopeRadians); // positive = uphill, negative = downhill
}