#define DEV 0

#pragma once

#include <Python.h>
#include <string>

#if !DEV
#include "CoreMinimal.h"

DECLARE_DELEGATE_TwoParams(FPyCall, const FString &, const FString &);

static FPyCall OnPyCall;

#endif // !DEV

PyMODINIT_FUNC
PyInit_ue_pylink(void);

class CPyInstance
{
public:
	~CPyInstance();

	bool StartPython();

	PyObject *ImportModule(std::string module_name = "");

	void StopPython();
};
