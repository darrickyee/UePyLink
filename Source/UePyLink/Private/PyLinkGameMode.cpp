// Fill out your copyright notice in the Description page of Project Settings.
#include "PyLinkGameMode.h"
#include "PyLink.h"
#include <Engine/Engine.h>
#include <string>

const char *to_char(FString fstr)
{
	return TCHAR_TO_UTF8(*fstr);
}

void APyLinkGameMode::_broadcast(const FString &Name, const FString &Data)
{
	OnPyBroadcast.Broadcast(Name, Data);
}

void APyLinkGameMode::_setpaths()
{
	const FString basedir = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("UePyLink"))->GetBaseDir());
	const FString contentdir = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

	FString moduledir = contentdir + (ModulePath.IsEmpty() ? "" : ModulePath);

	FString pyhome = basedir + "/Source/ThirdParty/Python";
	FString pypath = pyhome + "/Lib;" + pyhome + "/DLLs;" + moduledir;

	UE_LOG(LogLoad, Warning, TEXT("Pypath is %Ls"), *pypath);
	Py_SetProgramName(*(pyhome + "/python.exe"));
	Py_SetPath(*pypath);
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

			if (pReturn)
			{
				returnVal = FString(PyUnicode_AsUTF8(PyObject_Str(pReturn)));
			}
		}
	}
	else
	{
		printf("Error: No module loaded.");
	}

	return returnVal;
}

void APyLinkGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (*ModuleName && !Py_IsInitialized())
	{

		OnPyCall.BindUObject(this, &APyLinkGameMode::_broadcast);
		_setpaths();

		pModule = pInstance.StartPython(string(TCHAR_TO_UTF8(*ModuleName)));
		UE_LOG(LogLoad, Warning, TEXT("Path is %Ls"), Py_GetPath());
		UE_LOG(LogLoad, Warning, TEXT("Program is %Ls"), Py_GetProgramName());
	};
}