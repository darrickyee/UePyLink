// Fill out your copyright notice in the Description page of Project Settings.

#include "PyLinkSubsystem.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"
#include <string>

UPyLinkSubsystem::UPyLinkSubsystem()
{
	basePath = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("UePyLink"))->GetBaseDir());
	contentPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

	pyHome = basePath + "/Binaries/Win64/Python";

	OnPyCall.BindUObject(this, &UPyLinkSubsystem::PyBroadcast);
}

bool UPyLinkSubsystem::SetupPython()
{
	bool _valid = false;
	FString pyPath = "";

	// Check for Python executable
	const FString pyProgram = pyHome + "/python.exe";
	if (!FPaths::FileExists(pyProgram))
	{
		UE_LOG(LogLoad, Warning, TEXT("PyLink: Initialization failed: Could not find Program %Ls."), *pyProgram);
		return false;
	}

	// Check for standard libs
	if (FPaths::DirectoryExists(pyHome + "/Lib") && FPaths::DirectoryExists(pyHome + "/DLLs"))
	{
		pyPath = pyHome + "/Lib;" + pyHome + "/Lib/site-packages;" + pyHome + "/DLLs;";
		_valid = true;
	}
	else
	{
		for (int32 i = MAX_VERSION; i >= MIN_VERSION; i--)
		{
			if (FPaths::FileExists(pyHome + "/python3" + FString::FromInt(i) + ".zip"))
			{
				pyPath = pyHome + "/python3" + FString::FromInt(i) + ".zip;";
				_valid = true;
			}
		}
	}

	if (pyPath.IsEmpty())
	{
		UE_LOG(LogLoad, Warning, TEXT("PyLink: Initialization failed: No libraries in pyhome path %Ls."), *pyHome);
		return false;
	}

	// Check module directory
	pyPath += GetModulePath() + ";";
	if (!FPaths::DirectoryExists(GetModulePath()))
	{
		UE_LOG(LogLoad, Warning, TEXT("PyLink: Could not find module path %Ls.  Modules may not load correctly."), *(GetModulePath()));
	}

	if (_valid)
	{
		Py_SetProgramName(*pyProgram);
		Py_SetPath(*pyPath);

		return true;
	}

	return false;
}

bool UPyLinkSubsystem::StartPython()
{
	if (SetupPython())
	{
		return pyInstance.StartPython();
	}

	return false;
}

bool UPyLinkSubsystem::ImportModule(const FString &ModuleName)
{
	if (StartPython())
	{
		if (ModuleName.IsEmpty())
		{
			UE_LOG(LogLoad, Warning, TEXT("PyLink: ImportModule failed: No module specified."));
			return false;
		}

		if (!pModule)
		{
			pModule = pyInstance.ImportModule(std::string(TCHAR_TO_UTF8(*ModuleName)));
		}

		if (pModule)
		{
			UE_LOG(LogLoad, Display, TEXT("PyLink: Imported module '%Ls'."), *ModuleName);
			return true;
		}

		UE_LOG(LogLoad, Warning, TEXT("PyLink: ImportModule failed: Error loading module '%Ls'."), *ModuleName);
	}
	return false;
}

void UPyLinkSubsystem::StopPython()
{
	pyInstance.StopPython();
}

const FString UPyLinkSubsystem::GetModulePath(const bool absolute)
{
	return absolute ? contentPath + pyModulePath : pyModulePath;
}

void UPyLinkSubsystem::SetModulePath(const FString &newPath)
{
	pyModulePath = newPath.Contains(contentPath) ? newPath : contentPath + newPath;
}

FString UPyLinkSubsystem::CallPython(const FString &Function, const FString &Arg)
{
	FString returnVal = "";

	if (pModule)
	{
		PyObject *pFunc = PyObject_GetAttrString(pModule, TCHAR_TO_UTF8(*Function));

		if (pFunc && PyCallable_Check(pFunc))
		{
			PyObject *pReturn = PyObject_CallFunctionObjArgs(pFunc, PyUnicode_FromString(TCHAR_TO_UTF8(*Arg)), NULL);

			if (pReturn && pReturn != Py_None)
			{
				returnVal = FString(PyUnicode_AsUTF8(PyObject_Str(pReturn)));
			}
		}
		else
		{
			UE_LOG(LogLoad, Warning, TEXT("PyLink: Could not call function %Ls."), *Function);
		}
	}
	else
	{
		UE_LOG(LogLoad, Warning, TEXT("PyLink: Could not call function %Ls: No module loaded."), *Function);
	}

	return returnVal;
}

void UPyLinkSubsystem::PyBroadcast(const FString &Name, const FString &Data)
{
	OnPyBroadcast.Broadcast(FName(*Name), Data);
}