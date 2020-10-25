// Fill out your copyright notice in the Description page of Project Settings.

#include "PyLinkSubsystem.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"
#include <string>

DEFINE_LOG_CATEGORY(LogPyLink);

UPyLinkSubsystem::UPyLinkSubsystem()
{
	basePath = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("UePyLink"))->GetBaseDir());
	contentPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

	pyHome = basePath + "/Binaries/Win64/Python";

	OnPyCall.BindUObject(this, &UPyLinkSubsystem::PyDispatch);
	OnPyLog.BindUObject(this, &UPyLinkSubsystem::PyLog);
}

bool UPyLinkSubsystem::SetupPython()
{
	bool _valid = false;
	FString pyPath = "";

	// Check for Python executable
	const FString pyProgram = pyHome + "/python.exe";
	if (!FPaths::FileExists(pyProgram))
	{
		UE_LOG(LogPyLink, Warning, TEXT("Initialization failed: Could not find Program %Ls."), *pyProgram);
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
		UE_LOG(LogPyLink, Warning, TEXT("Initialization failed: No libraries in pyhome path %Ls."), *pyHome);
		return false;
	}

	// Check module directory
	const FString modPath = GetModulePath(true);
	if (FPaths::DirectoryExists(modPath))
	{
		pyPath += modPath + ";";
	}
	else
	{
		UE_LOG(LogPyLink, Warning, TEXT("Could not find module path %Ls.  Modules may not load correctly."), *modPath);
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
			UE_LOG(LogPyLink, Warning, TEXT("ImportModule failed: No module specified."));
			return false;
		}

		PyObject *mod = pyInstance.ImportModule(std::string(TCHAR_TO_UTF8(*ModuleName)));

		if (mod)
		{
			pModules.AddUnique(ModuleName);
			UE_LOG(LogPyLink, Display, TEXT("Imported module '%Ls'."), *ModuleName);
			return true;
		}

		LogError();
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
	pyModulePath = newPath;
	const FString modPath = GetModulePath(true);
	UE_LOG(LogPyLink, Display, TEXT("Module path set to '%Ls'."), *modPath);
	if (!FPaths::DirectoryExists(modPath))
	{
		UE_LOG(LogPyLink, Warning, TEXT("Module path could not be found.  Modules may not load correctly."));
	}
}

const FString UPyLinkSubsystem::CallPython(const FString &Function, const FString &Arg, const FString &ModuleName)
{
	FString returnVal = "";

	if (!pModules.Num())
	{
		UE_LOG(LogPyLink, Warning, TEXT("Could not call function '%Ls': No modules loaded."), *Function);
		return returnVal;
	}

	const FString modname = ModuleName.IsEmpty() ? pModules[0] : ModuleName;
	PyObject *mod = NULL;
	mod = GetModuleByName(modname);

	if (!mod)
	{
		UE_LOG(LogPyLink, Warning, TEXT("Could not call function '%Ls': Failed to load module '%Ls'."), *Function, *modname);
		return returnVal;
	}

	PyObject *pFunc = PyObject_GetAttrString(mod, TCHAR_TO_UTF8(*Function));

	if (!pFunc)
	{
		UE_LOG(LogPyLink, Warning, TEXT("Function '%Ls' not found in module '%Ls'."), *Function, *modname);
		return returnVal;
	}

	if (!PyCallable_Check(pFunc))
	{
		UE_LOG(LogPyLink, Warning, TEXT("Python object '%Ls' in module '%Ls' is not callable."), *Function, *modname);
		return returnVal;
	}

	PyObject *pReturn = PyObject_CallFunctionObjArgs(pFunc, PyUnicode_FromString(TCHAR_TO_UTF8(*Arg)), NULL);

	if (PyErr_Occurred())
	{
		LogError();
		return returnVal;
	}

	if (pReturn && pReturn != Py_None)
	{
		returnVal = FString(PyUnicode_AsUTF8(PyObject_Str(pReturn)));
	}

	return returnVal;
}

void UPyLinkSubsystem::PyDispatch(const FString &Name, const FString &Data)
{
	OnDispatch.Broadcast(FName(*Name), Data);
}

void UPyLinkSubsystem::PyLog(const FString &Message)
{
	UE_LOG(LogPyLink, Display, TEXT("[PyLog] %Ls"), *Message);
}

PyObject *UPyLinkSubsystem::GetModuleByName(const FString &ModuleName)
{
	PyObject *pModuleName = PyUnicode_FromString(TCHAR_TO_UTF8(*ModuleName));
	PyObject *pMod = PyImport_GetModule(pModuleName);
	return pMod;
}

const TArray<FString> UPyLinkSubsystem::GetImportedModules()
{
	const TArray<FString> rv = pModules;
	return rv;
}

void UPyLinkSubsystem::LogError()
{
	PyObject *type, *value, *traceback;
	PyErr_Fetch(&type, &value, &traceback);
	PyErr_NormalizeException(&type, &value, &traceback);

	if (!value)
	{
		PyErr_Clear();
		return;
	}

	char *msg = NULL;

	PyObject *zero = PyUnicode_AsUTF8String(PyObject_Str(value));
	if (zero)
	{
		msg = PyBytes_AsString(zero);
	}

	if (!msg)
	{
		PyErr_Clear();
		return;
	}

	UE_LOG(LogPyLink, Warning, TEXT("Python error: %s."), UTF8_TO_TCHAR(msg));

	if (!traceback)
	{
		PyErr_Clear();
		return;
	}

	PyObject *traceback_module = PyImport_ImportModule("traceback");
	if (!traceback_module)
	{
		PyErr_Clear();
		return;
	}

	PyObject *traceback_dict = PyModule_GetDict(traceback_module);
	PyObject *format_exception = PyDict_GetItemString(traceback_dict, "format_exception");

	if (format_exception)
	{
		PyObject *ret = PyObject_CallFunctionObjArgs(format_exception, type, value, traceback, NULL);
		if (!ret)
		{
			PyErr_Clear();
			return;
		}
		if (PyList_Check(ret))
		{
			for (int i = 0; i < PyList_Size(ret); i++)
			{
				PyObject *item = PyList_GetItem(ret, i);
				if (item)
				{
					UE_LOG(LogPyLink, Error, TEXT("%s"), UTF8_TO_TCHAR(PyUnicode_AsUTF8(PyObject_Str(item))));
				}
			}
		}
		else
		{
			UE_LOG(LogPyLink, Error, TEXT("%s"), UTF8_TO_TCHAR(PyUnicode_AsUTF8(PyObject_Str(ret))));
		}
	}

	PyErr_Clear();
}