// Fill out your copyright notice in the Description page of Project Settings.
#include "PyLinkGameMode.h"
#include "PyLink.h"
#include <include/Python.h>
#include "Engine/Engine.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include <string>


PyMODINIT_FUNC
PyInit_ue_pylink(void)
{
	return PyModule_Create(&moddef);
}

void APyLinkGameMode::_broadcast(const FString &Name, const FString &Data)
{
	OnPyBroadcast.Broadcast(Name, Data);
}

FString APyLinkGameMode::CallPython(const FString &Function, const FString &Data)
{
	FString returnVal = TEXT("");

	if (pModule)
	{
		PyObject *pFunc = PyObject_GetAttrString(pModule, TCHAR_TO_UTF8(*Function));

		if (pFunc && PyCallable_Check(pFunc))
		{
			PyObject *pArg = PyTuple_New(1);
			PyTuple_SetItem(pArg, 0, PyUnicode_FromString(TCHAR_TO_UTF8(*Data)));
			PyObject *pReturn = PyObject_CallObject(pFunc, pArg);

			if (pReturn)
			{
				returnVal = FString(PyUnicode_AsUTF8(PyObject_Str(pReturn)));
			}
		}
	}

	return returnVal;
}

void APyLinkGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (*ModuleName && !pModule)
	{
		OnPyCall.BindUObject(this, &APyLinkGameMode::_broadcast);

		PyImport_AppendInittab("ue_pylink", &PyInit_ue_pylink);

		std::string _modpath = TCHAR_TO_UTF8(*(FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()) + TEXT("/Scripts")));
		if (!ModulePath.IsEmpty())
		{
			_modpath += TCHAR_TO_UTF8(*ModulePath);
		}
		std::string pyPathCmd = "sys.path.append('" + _modpath + "')\n";
		pInstance.Init();

		PyRun_SimpleString("import sys\n");
		PyRun_SimpleString(pyPathCmd.c_str());

		pModule = PyImport_ImportModule(TCHAR_TO_UTF8(*ModuleName));
		// GEngine->AddOnScreenDebugMessage(-10, 5.f, FColor::Red, FString(PyUnicode_AsUTF8(PyObject_Str(pModule))));
	};
}