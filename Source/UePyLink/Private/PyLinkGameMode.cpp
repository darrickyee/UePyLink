// Fill out your copyright notice in the Description page of Project Settings.
#include "PyLinkGameMode.h"
#include "PyLink.h"
#include <include/Python.h>
#include "Engine/Engine.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include <string>

void APyLinkGameMode::_broadcast(const FString &Name, const FString &Data)
{
	OnPyBroadcast.Broadcast(Name, Data);
}

void APyLinkGameMode::_setpaths()
{
	// const FString pluginbasedir = IPluginManager::Get().FindPlugin(TEXT("UePyLink"))->GetBaseDir();
	/*
	Needs type conversion
	Py_SetProgramName(_convert to wchar_t_ pluginbasedir + L"/Binaries/Win64/Python/python.exe");
	Py_SetPath(-add python zip path or home path- -add game Content/Scripts);
	*/
}

FString APyLinkGameMode::CallPython(const FString &Function, const FString &Arg)
{
	FString returnVal = TEXT("");

	if (pModule)
	{
		PyObject *pFunc = PyObject_GetAttrString(pModule, TCHAR_TO_UTF8(*Function));

		if (pFunc && PyCallable_Check(pFunc))
		{
			PyObject *pReturn = PyObject_CallFunctionObjArgs(pFunc, PyUnicode_FromString(Arg.c_str()), NULL);

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
		// Need to set paths somewhere
		OnPyCall.BindUObject(this, &APyLinkGameMode::_broadcast);

		// Need to convert ModuleName to string
		pModule = pInstance.StartPython(string(TCHAR_TO_UTF8(*ModuleName)));
	};
}