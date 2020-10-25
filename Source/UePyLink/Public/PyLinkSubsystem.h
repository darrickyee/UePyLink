// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Python.h>
#include "PyLink.h"
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PyLinkSubsystem.generated.h"

#define MIN_VERSION 5
#define MAX_VERSION 9

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPyDispatch, const FName &, Name, const FString &, Data);

DECLARE_LOG_CATEGORY_EXTERN(LogPyLink, Log, All);

UCLASS()
class UEPYLINK_API UPyLinkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPyLinkSubsystem();

	// Called when ue_pylink.dispatch(Name, Data) is called in Python.
	UPROPERTY(BlueprintAssignable, Category = "PyLink")
	FPyDispatch OnDispatch;

	// Returns a list of currently imported modules.
	UFUNCTION(BlueprintPure, Category = "PyLink")
	const TArray<FString> GetImportedModules();

	/* Prepares the Python interpreter for initialization by checking if 
	the interpreter executable and libraries are available in the plugin's
	/Binaries/Win64/Python directory and the module directory specified by 
	GetModulePath() exists.  Returns true if successful.

	This method is automatically called by StartPython().
	*/
	UFUNCTION(BlueprintCallable, Category = "PyLink")
	bool SetupPython();

	/* Starts the Python interpreter but does not load any modules.  Will fail if
	SetupPython() fails.  Does nothing if the interpreter is already active.

	This method is automatically called by ImportModule().
	*/
	UFUNCTION(BlueprintCallable, Category = "PyLink")
	bool StartPython();

	// Stops the Python interpreter if it is active.
	UFUNCTION(BlueprintCallable, Category = "PyLink")
	void StopPython();

	/* Starts the Python interpreter if it is not already started and
	imports the specified module or package.  Searches relative to the path
	specified by GetModulePath().

	@param ModuleName The name of the module or package to import.
	*/
	UFUNCTION(BlueprintCallable, Category = "PyLink")
	bool ImportModule(const FString &ModuleName);

	/* Gets the base path from which ImportModule() will search for modules.  Relative 
	to the project's Content path if absolute == false.

	@param absolute Return the full path if true; otherwise, return the path relative to the project Content directory.
	*/
	UFUNCTION(BlueprintPure, Category = "PyLink")
	const FString GetModulePath(const bool absolute = false);

	/* Sets the base path from which ImportModule() will search for modules, relative
	to the project's Content directory.

	@param newPath Path to module files, relative to the project Content directory.
	*/
	UFUNCTION(BlueprintCallable, Category = "PyLink")
	void SetModulePath(const FString &newPath = "Scripts");

	/* Calls the Python function Function in module ModuleName with string argument Arg.

	@param Function The name of the function to call.
	@param Arg Single argument to be passed to the function.
	@param ModuleName The module in which the function should be called.  Defaults to the first module returned by GetImportedModules().
	*/
	UFUNCTION(BlueprintCallable, Category = "PyLink")
	const FString CallPython(const FString &Function, const FString &Arg, const FString &ModuleName = "");

private:
	PyObject *GetModuleByName(const FString &ModuleName);
	void PyDispatch(const FString &Name, const FString &Data);
	void PyLog(const FString &Message);
	void LogError();

	PyObject *pModule = NULL;

	UPROPERTY()
	TArray<FString> pModules;

	CPyInstance pyInstance;

	FString basePath;
	FString contentPath;
	FString pyHome;
	FString pyModulePath = "Scripts";
};
