// Fill out your copyright notice in the Description page of Project Settings.
#include "PyLinkGameMode.h"
#include "Misc/Paths.h"
#include <string>

const char *to_char(FString fstr)
{
	return TCHAR_TO_UTF8(*fstr);
}

void APyLinkGameMode::PyBroadcast(const FString &Name, const FString &Data)
{
	OnPyBroadcast.Broadcast(Name, Data);
}

bool APyLinkGameMode::IsValidConfig()
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
		UE_LOG(LogLoad, Warning, TEXT("Python: Initialization failed: Could not find Program %Ls."), *progname);
		return false;
	}

	if (!FPaths::DirectoryExists(moduledir))
	{
		UE_LOG(LogLoad, Warning, TEXT("Python: Initialization failed: Could not find module path %Ls."), *moduledir);
		return false;
	}

	if (FPaths::DirectoryExists(pyhome + "/Lib") && FPaths::DirectoryExists(pyhome + "/DLLs"))
	{
		pypath = pyhome + "/Lib;" + pyhome + "/DLLs;";
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

	UE_LOG(LogLoad, Warning, TEXT("Python: Initialization failed: No libraries in pyhome path %Ls."), *pyhome);

	return false;
}

FString APyLinkGameMode::CallPython(const FString &Function, const FString &Arg)
{
	FString returnVal = TEXT("");

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
			UE_LOG(LogLoad, Warning, TEXT("Python: Could not call function %Ls."), *Function);
		}
	}
	else
	{
		UE_LOG(LogLoad, Warning, TEXT("Python: Could not call function %Ls: No module loaded."), *Function);
	}

	return returnVal;
}

void APyLinkGameMode::BeginPlay()
{
	if (!ModuleName.IsEmpty())
	{
		if (!Py_IsInitialized())
		{
			OnPyCall.BindUObject(this, &APyLinkGameMode::PyBroadcast);
			if (IsValidConfig())
			{
				pModule = pInstance.StartPython(string(TCHAR_TO_UTF8(*ModuleName)));
			}

			if (pModule)
			{
				UE_LOG(LogLoad, Display, TEXT("Python: Using interpreter at %Ls"), Py_GetProgramName());
				UE_LOG(LogLoad, Display, TEXT("Python: Path is %Ls"), Py_GetPath());
			}
			else
			{
				UE_LOG(LogLoad, Warning, TEXT("Python: Could not load module %Ls."), *ModuleName);
			}
		}
		else
		{
			UE_LOG(LogLoad, Warning, TEXT("Python: Initialization failed: Already initialized."));
		}
	}
	else
	{
		UE_LOG(LogLoad, Warning, TEXT("Python: Initialization failed: No module specified."));
	};

	Super::BeginPlay();
}