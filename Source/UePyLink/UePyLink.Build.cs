// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;
using System.IO;
using System.Collections.Generic;

public class UePyLink : ModuleRules
{
	int MIN_VERSION = 5;
	int MAX_VERSION = 9;
	public UePyLink(ReadOnlyTargetRules Target): base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		// Use PluginDirectory property instead?
		string PythonDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "..\\..\\Binaries\\Win64\\Python"));

        // Headers path
		string pyInclude = Path.Combine(PythonDir, "include");
		if (Directory.Exists(pyInclude))
		{
			PublicIncludePaths.Add(pyInclude);
		}
		else
		{
			throw new System.Exception("[UePyLink] Error: Could not find include director:y '{0}'", pyInclude);
		}

        // Libs path
		List<string> pyLibs = new List<string>();
		for (int i = MAX_VERSION; i >= MIN_VERSION; i--)
		{
			string libFile = Path.Combine(PythonDir, string.Format("libs\\python3{0}.lib", i));
			if (File.Exists(libFile))
			{
				pyLibs.Add(libFile);
				PublicAdditionalLibraries.Add(libFile);
				System.Console.WriteLine(string.Format("[UePyLink] Using lib at '{0}'", libFile));
				break;
			}
		}

		if (pyLibs.Count == 0)
		{
			throw new System.Exception("[UePyLink] Error: Could not find .lib file.");
		}

		PublicDependencyModuleNames.AddRange(new string[]{"Core", // ... add other public dependencies that you statically link with here ...
		});

		PrivateDependencyModuleNames.AddRange(new string[]{"CoreUObject", "Engine", "Slate", "SlateCore", // ... add private dependencies that you statically link with here ...	
		"Projects" // Required for IPluginManager
		});

	}
}