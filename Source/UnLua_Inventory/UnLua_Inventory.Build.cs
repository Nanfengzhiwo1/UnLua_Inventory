// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnLua_Inventory : ModuleRules
{
	public UnLua_Inventory(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
