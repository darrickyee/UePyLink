#define DEV 0

#ifndef _UEPYLINK_INIT
#define _UEPYLINK_INIT
#include <Python.h>
#include <string>

using namespace std;

#if DEV
#include <Python.h>
static PyObject *ue_pylink_broadcast(PyObject *self, PyObject *pArgs)
{

	PyObject *arg1;
	PyObject *arg2 = Py_None;
	if (PyArg_ParseTuple(pArgs, "O|O", &arg1, &arg2))
	{
		const char *nameArg = PyUnicode_AsUTF8(PyObject_Str(arg1));
		const char *dataArg = (arg2 == Py_None) ? "" : PyUnicode_AsUTF8(PyObject_Str(arg2));
		printf("Received broadcast with Name: %s, Data: %s", nameArg, dataArg);
	}

	Py_RETURN_NONE;
};

#else
#include "CoreMinimal.h"

DECLARE_DELEGATE_TwoParams(FPyCall, const FString &, const FString &);

static FPyCall OnPyCall;

static PyObject *ue_pylink_broadcast(PyObject *self, PyObject *pArgs)
{
	PyObject *arg1;
	PyObject *arg2 = Py_None;
	if (PyArg_ParseTuple(pArgs, "O|O", &arg1, &arg2))
	{
		const char *nameArg = PyUnicode_AsUTF8(PyObject_Str(arg1));
		const char *dataArg = (arg2 == Py_None) ? "" : PyUnicode_AsUTF8(PyObject_Str(arg2));
		OnPyCall.ExecuteIfBound(FString(nameArg), FString(dataArg));
	}

	Py_RETURN_NONE;
};
#endif

static struct PyMethodDef methods[] = {
	{"broadcast", ue_pylink_broadcast, METH_VARARGS, "Broadcast data to UE4"},
	{NULL, NULL, 0, NULL}};

static struct PyModuleDef moddef = {
	PyModuleDef_HEAD_INIT, "ue_pylink", NULL, -1, methods, NULL, NULL, NULL, NULL};

PyMODINIT_FUNC
PyInit_ue_pylink(void);

class CPyInstance
{
public:
	CPyInstance();
	~CPyInstance();

	PyObject *StartPython(string module_name = "");

private:
	PyObject *pModule;
	string ModuleName;
};
#endif // !_UEPYLINK_INIT