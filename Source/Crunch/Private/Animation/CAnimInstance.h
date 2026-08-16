// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	// the below functions are the native overrides for each phase
	// Native initialization override point
	virtual void NativeInitializeAnimation() override;
	// Native update override point. It is usually a good idea to simply gather data in this step and 
	// for the bulk of the work to be done in NativeThreadSafeUpdateAnimation.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	// Native thread safe update override point. Executed on a worker thread just prior to graph update 
	// for linked anim instances, only called when the hosting node(s) are relevant
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

						  
	UFUNCTION(BlueprintCallable, meta=(BlueprintThreadSafe))
	FORCEINLINE float GetSpeed() const { return Speed; }

	UFUNCTION(BlueprintCallable, meta=(BlueprintThreadSafe))
	FORCEINLINE bool IsMoving() const { return Speed != 0; }

	UFUNCTION(BlueprintCallable, meta=(BlueprintThreadSafe))
	FORCEINLINE bool IsNotMoving() const { return Speed == 0; }

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE float GetSmoothedYawSpeed() const { return SmoothedYawSpeed; }

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE bool IsJumping() const { return bIsJumping; }

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE bool IsFalling() const { return !bIsJumping; }


	UFUNCTION(BlueprintCallable, Category = "Animation", meta = (BlueprintThreadSafe))
	float CalculateLeanAngle() const;
	UFUNCTION(BlueprintCallable, Category = "Animation", meta = (BlueprintThreadSafe))
	float CalculateSlopeAngle() const;
private:
	 
	UPROPERTY()
	class ACharacter* OwnerCharacter = nullptr;

	UPROPERTY()
	class UCharacterMovementComponent* OwnerMovementComponent = nullptr;

	float Speed;
	float SmoothedYawSpeed;
	float LeanAngle = 0.f;
	float SlopeAngle = 0.f;

	UPROPERTY(EditAnywhere, Category = "Animation")
	float SlopeInterpSpeed = 10.f;

	UPROPERTY(EditAnywhere, Category = "Animation")
	float LeanScale = 0.6f;

	UPROPERTY(EditAnywhere, Category = "Animation")
	float MaxLeanAngle = 45.f;

	bool bIsJumping;



	





};
