// Fill out your copyright notice in the Description page of Project Settings.

#include "PyLinkSubsystem.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"
#include <string>

FString UPyLinkSubsystem::DoSomething()
{
	FString rv = TEXT("Called DoSomething()");
	return rv;
}

bool UPyLinkSubsystem::LoadModule(const FString &ModuleName, const FString &ModulePath)
{
	return IsValidConfig(ModulePath);
}

bool UPyLinkSubsystem::IsValidConfig(const FString &ModulePath)
{
	const FString basedir = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("UePyLink"))->GetBaseDir());
	const FString contentdir = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

	const FString moduledir = contentdir + (ModulePath.IsEmpty() ? "" : ModulePath);
	const FString pyhome = basedir + "/Binaries/Win64/Python";

	const FString progname = pyhome + "/python.exe";

	bool _valid = false;
	FString pypath;

	if (!FPaths::FileExists(progname))
	{
		UE_LOG(LogLoad, Warning, TEXT("PyLink: Initialization failed: Could not find Program %Ls."), *progname);
		return false;
	}

	if (!FPaths::DirectoryExists(moduledir))
	{
		UE_LOG(LogLoad, Warning, TEXT("PyLink: Initialization failed: Could not find module path %Ls."), *moduledir);
		return false;
	}

	if (FPaths::DirectoryExists(pyhome + "/Lib") && FPaths::DirectoryExists(pyhome + "/DLLs"))
	{
		pypath = pyhome + "/Lib;" + pyhome + "/Lib/site-packages;" + pyhome + "/DLLs;";
		_valid = true;
	}
	else
	{
		for (int32 i = MAX_VERSION; i >= MIN_VERSION; i--)
		{
			if (FPaths::FileExists(pyhome + "/python3" + FString::FromInt(i) + ".zip"))
			{
				pypath = pyhome + "/python3" + FString::FromInt(i) + ".zip;";
				_valid = true;
			}
		}
	}

	if (_valid)
	{
		Py_SetProgramName(*progname);
		pypath += moduledir;
		Py_SetPath(*pypath);

		return true;
	}

	UE_LOG(LogLoad, Warning, TEXT("PyLink: Initialization failed: No libraries in pyhome path %Ls."), *pyhome);

	return false;
}