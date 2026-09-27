// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ValueGuage.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


 // Add default functionality here for any IValueGuage functions that are not pure virtual.
void UValueGuage::NativePreConstruct()
{
	Super::NativeConstruct();
	ProgressBar->SetFillColorAndOpacity(BarColor);
	
}

// Set the value and max value of the gauge, and update the progress bar and text accordingly
void UValueGuage::SetValue(float NewValue, float NewMaxValue)
{
	if (NewMaxValue == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("NewMaxValue is zero, cannot set value."));
		return;
	}

	float Percent = NewValue / NewMaxValue;
	ProgressBar->SetPercent(Percent);

	// Format the value as a percentage with no decimal places
	FNumberFormattingOptions FormatOpts = FNumberFormattingOptions().SetMaximumFractionalDigits(0);
	ValueText->SetText(
			FText::Format (
				FTextFormat::FromString("{0}/{1}"),
				FText::AsNumber(NewValue, &FormatOpts),
				FText::AsNumber(NewMaxValue, &FormatOpts
				)
			)
	);
}
