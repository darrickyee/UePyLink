// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

int MIN_VERSION = 5;
int MAX_VERSION = 9;

public class UePyLink : ModuleRules
{
    public UePyLink(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        string PythonDir = System.IO.Path.GetFullPath(System.IO.Path.Combine(ModuleDirectory, "..\\..\\Binaries\\Win64\\Python"));

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
                System.IO.Path.Combine(PythonDir, "include")
            }
            );

        for (int i = MAX_VERSION; i >= MIN_VERSION; i--)
        {
            string libFile = System.IO.Path.Combine(PythonDir, string.Format("libs\\python3{0}.lib", i));
            if (System.IO.File.Exists(libFile))
            {
                PublicAdditionalLibraries.Add(libFile);
                System.Console.WriteLine(string.Format("[UePyLink] Using lib at {0}", libFile));
            }
        }

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
