// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayWidget.generated.h"

/**
 * 
 */
class UValueGuage;
UCLASS()

class UGameplayWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

private:

	UPROPERTY(meta = (BindWidget))
	 UValueGuage* HealthBar;

	UPROPERTY(meta = (BindWidget))
	 UValueGuage* ManaBar;

};
