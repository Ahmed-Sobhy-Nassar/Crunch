// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

// Build target configuration for the standalone game (packaged/shipped builds)
public class CrunchTarget : TargetRules
{
	public CrunchTarget(TargetInfo Target) : base(Target)
	{
		// Target type: Game (standalone executable, no editor)
		Type = TargetType.Game;
		// Use the latest UE 5.5 build settings
		DefaultBuildSettings = BuildSettingsVersion.V5;
		// Use UE 5.5 include order for header resolution
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		// Include the primary game module
		ExtraModuleNames.Add("Crunch");
	}
}
