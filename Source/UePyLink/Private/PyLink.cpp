#include "PyLink.h"

#if DEV

static PyObject *ue_pylink_broadcast(PyObject *self, PyObject *pArgs)
{

	PyObject *arg1;
	PyObject *arg2 = Py_None;
	if (PyArg_ParseTuple(pArgs, "O|O", &arg1, &arg2))
	{
		const char *nameArg = PyUnicode_AsUTF8(PyObject_Str(arg1));
		const char *dataArg = (arg2 == Py_None) ? "" : PyUnicode_AsUTF8(PyObject_Str(arg2));
		printf("PyLink: Received broadcast with Name: %s, Data: %s", nameArg, dataArg);
	}

	Py_RETURN_NONE;
};

#else
static PyObject *ue_pylink_broadcast(PyObject *self, PyObject *pArgs)
{
	PyObject *arg1 = Py_None;
	PyObject *arg2 = Py_None;
	if (PyArg_ParseTuple(pArgs, "O|O", &arg1, &arg2))
	{
		const char *nameArg = (arg1 == Py_None) ? "" : PyUnicode_AsUTF8(PyObject_Str(arg1));
		const char *dataArg = (arg2 == Py_None) ? "" : PyUnicode_AsUTF8(PyObject_Str(arg2));
		OnPyCall.ExecuteIfBound(FString(nameArg), FString(dataArg));
	}

	Py_RETURN_NONE;
};

#endif // !DEV

static PyObject *ue_pylink_log(PyObject *self, PyObject *pMsg)
{
	PyObject *arg = Py_None;
	if (PyArg_ParseTuple(pMsg, "O", &arg))
	{
		const char *msgArg = (arg == Py_None) ? "" : PyUnicode_AsUTF8(PyObject_Str(arg));
		OnPyLog.ExecuteIfBound(FString(msgArg));
	}

	Py_RETURN_NONE;
};

// Expose functions & module to Python
static struct PyMethodDef methods[] = {
	{"dispatch", ue_pylink_broadcast, METH_VARARGS, "Dispatch event to UE4"},
	{"log", ue_pylink_log, METH_VARARGS, "Log event to UE4 console"},
	{NULL, NULL, 0, NULL}};

static struct PyModuleDef moddef = {
	PyModuleDef_HEAD_INIT, "ue_pylink", NULL, -1, methods, NULL, NULL, NULL, NULL};

PyMODINIT_FUNC
PyInit_ue_pylink(void)
{
	return PyModule_Create(&moddef);
}

bool CPyInstance::StartPython()
{
	if (!Py_IsInitialized())
	{
		PyImport_AppendInittab("ue_pylink", &PyInit_ue_pylink);
		Py_Initialize();
	}

	return Py_IsInitialized();
}

PyObject *CPyInstance::ImportModule(std::string module_name)
{
	if (!module_name.empty())
	{
		if (!Py_IsInitialized())
		{
			StartPython();
		}

		if (Py_IsInitialized())
		{
			PyObject *pModule = PyImport_ImportModule(module_name.c_str());
			return pModule;
		}
	}

	return NULL;
}

void CPyInstance::StopPython()
{
	Py_Finalize();
}

CPyInstance::~CPyInstance()
{
	StopPython();
}