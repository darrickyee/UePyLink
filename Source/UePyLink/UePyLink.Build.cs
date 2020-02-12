// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UePyLink : ModuleRules
{
    public UePyLink(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        string PythonDir = System.IO.Path.Combine(ModuleDirectory, "..", "ThirdParty", "Python");

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
                System.IO.Path.Combine(PythonDir, "include")
            }
            );

        PublicLibraryPaths.Add(System.IO.Path.Combine(PythonDir, "libs"));

        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
			}
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
				// ... add other public dependencies that you statically link with here ...
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
                "Projects" // Required for IPluginManager
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
