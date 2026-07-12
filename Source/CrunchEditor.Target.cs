// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

// Build target configuration for the Unreal Editor (development/editing builds)
public class CrunchEditorTarget : TargetRules
{
	public CrunchEditorTarget( TargetInfo Target) : base(Target)
	{
		// Target type: Editor (includes editor tools and UI)
		Type = TargetType.Editor;
		// Use the latest UE 5.5 build settings
		DefaultBuildSettings = BuildSettingsVersion.V5;
		// Use UE 5.5 include order for header resolution
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		// Include the primary game module
		ExtraModuleNames.Add("Crunch");
	}
}
