#include "PyLink.h"
#include "CoreMinimal.h"
#include <include/Python.h>

CPyInstance::CPyInstance()
{
}

void CPyInstance::Init()
{
	Py_Initialize();
}

CPyInstance::~CPyInstance()
{
	Py_Finalize();
}
