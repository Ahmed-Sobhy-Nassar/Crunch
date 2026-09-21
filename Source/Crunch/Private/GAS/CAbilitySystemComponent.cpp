// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CAbilitySystemComponent.h"

void UCAbilitySystemComponent::ApplyGameplayEffects()
{
	if(!GetOwner() || !GetOwner()->HasAuthority()) return;
	for(const TSubclassOf<UGameplayEffect> EffectClass : InitialEffects)
	{
		FGameplayEffectSpecHandle EffectSpectHandle = MakeOutgoingSpec(EffectClass, 1, MakeEffectContext());

		ApplyGameplayEffectSpecToSelf(*EffectSpectHandle.Data.Get());
	}
}
