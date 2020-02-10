#ifndef _UEPYLINK_INIT
#define _UEPYLINK_INIT
#include "CoreMinimal.h"
#include <include/Python.h>

class CPyInstance
{
public:
	CPyInstance();
	void Init();
	~CPyInstance();
};

DECLARE_DELEGATE_TwoParams(FPyCall, const FString &, const FString &);

static FPyCall OnPyCall;

static PyObject *ue_pylink_broadcast(PyObject *self, PyObject *pArgs)
{

	char *arg1;
	char *arg2 = "";
	if (PyArg_ParseTuple(pArgs, "s|s", &arg1, &arg2))
	{

		OnPyCall.ExecuteIfBound(FString(arg1), FString(arg2));
	}

	Py_RETURN_NONE;
};

static struct PyMethodDef methods[] = {
	{"broadcast", ue_pylink_broadcast, METH_VARARGS, "Broadcast data to UE4"},
	{NULL, NULL, 0, NULL} };

static struct PyModuleDef moddef = {
	PyModuleDef_HEAD_INIT, "ue_pylink", NULL, -1, methods, NULL, NULL, NULL, NULL };

#endif // !_UEPYLINK_INIT