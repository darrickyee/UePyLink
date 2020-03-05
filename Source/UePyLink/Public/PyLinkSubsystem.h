// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Python.h>
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PyLinkSubsystem.generated.h"

#define MIN_VERSION 5
#define MAX_VERSION 9

/**
 * 
 */
UCLASS()
class UEPYLINK_API UPyLinkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FString DoSomething();

	UFUNCTION(BlueprintCallable)
	bool LoadModule(const FString &ModuleName, const FString &ModulePath = "Scripts");

	UFUNCTION(BlueprintCallable)
	bool IsValidConfig(const FString &ModulePath);

private:
	PyObject *pModule = NULL;
};
