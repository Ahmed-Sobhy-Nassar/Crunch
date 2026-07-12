// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Core minimal types (FVector, FString, etc.)
#include "CoreMinimal.h"
// Base game mode class for defining game rules, player spawning, and default classes
#include "GameFramework/GameModeBase.h"
// Generated header for Unreal reflection and serialization
#include "CGameMode.generated.h"

/**
 * ACGameMode - Custom game mode for the Crunch project.
 * Currently an empty stub class, ready for future implementation
 * of game rules, player pawn defaults, HUD class, and match logic.
 */
UCLASS()
class ACGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
};
