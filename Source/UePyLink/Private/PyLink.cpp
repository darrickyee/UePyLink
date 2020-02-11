#include "PyLink.h"
#if DEV
#include <Python.h>

#else
#include "CoreMinimal.h"
#include <include/Python.h>

#endif

PyMODINIT_FUNC
PyInit_ue_pylink(void)
{
	return PyModule_Create(&moddef);
}

CPyInstance::CPyInstance() : ModuleName{""}, pModule{0}
{
}

PyObject *CPyInstance::StartPython(string module_name)
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
