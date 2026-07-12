// Copyright Epic Games, Inc. All Rights Reserved.

// Include the module header for the primary game module
#include "Crunch.h"
// Include the module manager for registering the game module
#include "Modules/ModuleManager.h"

// Register this as the primary game module for the Crunch project
// FDefaultGameModuleImpl provides default module startup/shutdown behavior
IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Crunch, "Crunch" );
