// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class EOSHookCrash : ModuleRules
{
	public EOSHookCrash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        OptimizeCode = CodeOptimization.Never;

        PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
        PrivateIncludePaths.AddRange(
            new string[] {
                Path.Combine(EngineDirectory,"Source/Runtime/D3D12RHI/Private"),
            }
            );

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Projects"
				// ... add other public dependencies that you statically link with here ...
			}
            );
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Engine",
                "RHI",
                "D3D12RHI",
            }
            );
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        AddEngineThirdPartyPrivateStaticDependencies(Target, "DX12");
        PublicSystemLibraries.Add("dxgi.lib");
    }
}
