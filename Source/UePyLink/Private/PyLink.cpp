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

#endif // !DEV

// Expose functions & module to Python
static struct PyMethodDef methods[] = {
	{"broadcast", ue_pylink_broadcast, METH_VARARGS, "Broadcast data to UE4"},
	{NULL, NULL, 0, NULL}};

static struct PyModuleDef moddef = {
	PyModuleDef_HEAD_INIT, "ue_pylink", NULL, -1, methods, NULL, NULL, NULL, NULL};

PyMODINIT_FUNC
PyInit_ue_pylink(void)
{
	return PyModule_Create(&moddef);
}

// Python manager
CPyInstance::CPyInstance() : pModule{0}, ModuleName{""}
{
}

PyObject *CPyInstance::StartPython(std::string module_name)
{
	if (!module_name.empty())
	{
		ModuleName = module_name;
	}

	if (!ModuleName.empty())
	{
		if (!Py_IsInitialized())
		{
			PyImport_AppendInittab("ue_pylink", &PyInit_ue_pylink);
			Py_Initialize();

			if (Py_IsInitialized() && !pModule)
			{
				pModule = PyImport_ImportModule(ModuleName.c_str());
				return pModule;
			}
		}
	}

	return NULL;
}

CPyInstance::~CPyInstance()
{
	Py_Finalize();
}
