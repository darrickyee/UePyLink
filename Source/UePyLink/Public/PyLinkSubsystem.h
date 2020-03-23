// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Python.h>
#include "PyLink.h"
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PyLinkSubsystem.generated.h"

#define MIN_VERSION 5
#define MAX_VERSION 8

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPyBroadcast, const FName &, Name, const FString &, Data);

DECLARE_LOG_CATEGORY_EXTERN(LogPyLink, Log, All);

UCLASS()
class UEPYLINK_API UPyLinkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPyLinkSubsystem();

	// Called when ue_pylink.broadcast(Name, Data) is called in Python.
	UPROPERTY(BlueprintAssignable, Category = "PyLink")
	FPyBroadcast OnPyBroadcast;

	UFUNCTION(BlueprintPure, Category = "PyLink")
	const TArray<FString> GetImportedModules();

	UFUNCTION(BlueprintCallable, Category = "PyLink")
	bool SetupPython();

	UFUNCTION(BlueprintCallable, Category = "PyLink")
	bool StartPython();

	UFUNCTION(BlueprintCallable, Category = "PyLink")
	void StopPython();

	UFUNCTION(BlueprintCallable, Category = "PyLink")
	bool ImportModule(const FString &ModuleName);

	UFUNCTION(BlueprintPure, Category = "PyLink")
	const FString GetModulePath(const bool absolute = true);

	UFUNCTION(BlueprintCallable, Category = "PyLink")
	void SetModulePath(const FString &newPath = "Scripts");

	UFUNCTION(BlueprintCallable, Category = "PyLink")
	const FString CallPython(const FString &Function, const FString &Arg, const FString &ModuleName = "");

private:
	PyObject *GetModuleByName(const FString &ModuleName);
	void PyBroadcast(const FString &Name, const FString &Data);
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
