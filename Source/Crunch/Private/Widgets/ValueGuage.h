// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ValueGuage.generated.h"

/**
 * 
 */
UCLASS()
class UValueGuage : public UUserWidget
{
	GENERATED_BODY()
	


public:
	virtual void NativePreConstruct() override;
	void SetValue(float NewValue, float NewMaxValue);
private:
	UPROPERTY(EditAnywhere, Category = "Visula")
	FLinearColor BarColor;

	UPROPERTY(VisibleAnywhere, meta =(BindWidget))
	class UProgressBar* ProgressBar;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
	class UTextBlock* ValueText;
};
