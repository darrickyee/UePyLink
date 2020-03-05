// Fill out your copyright notice in the Description page of Project Settings.
#include "CoreMinimal.h"
#include "PyLink.h"
#include "Interfaces/IPluginManager.h"
#include "GameFramework/GameModeBase.h"
#include "PyLinkGameMode.generated.h"

#define MIN_VERSION 5
#define MAX_VERSION 8

/**
 * 
 */
UCLASS()
class UEPYLINK_API APyLinkGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPyBroadcast, const FName &, Name, const FString &, Data);

	// Called when ue_pylink.broadcast(Name, Data) is called in Python.
	UPROPERTY(BlueprintAssignable, Category = "PyLink")
	FPyBroadcast OnPyBroadcast;

	// Call a Python function with a single str argument.
	UFUNCTION(BlueprintCallable, Category = "PyLink")
	FString CallPython(const FString &Function, const FString &Arg = "");

	// Name of Python module to load.  E.g., 'mymodule'
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModuleName;

	// Path to module, relative to Content directory.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModulePath = FString(TEXT("Scripts"));

	virtual void BeginPlay() override;

private:
	PyObject *pModule = 0;
	CPyInstance pInstance;

	void PyBroadcast(const FString &Name, const FString &Data);
	bool IsValidConfig();
};
