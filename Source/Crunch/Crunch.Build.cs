// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

// Module build rules for the Crunch game module
public class Crunch : ModuleRules
{
	public Crunch(ReadOnlyTargetRules Target) : base(Target)
	{
		// Use explicit or shared precompiled headers for faster compilation
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		// Public dependencies: modules this module exposes to other modules
		// Core: base UE types and utilities
		// CoreUObject: UObject system, reflection, and serialization
		// Engine: gameplay framework (actors, components, game modes, etc.)
		// InputCore: basic input types and interfaces
		// EnhancedInput: modern input system with action mappings
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		// Private dependencies: modules used internally but not exposed to dependents
		PrivateDependencyModuleNames.AddRange(new string[] { "EnhancedInput" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
