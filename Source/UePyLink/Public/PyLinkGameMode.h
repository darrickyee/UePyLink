// Fill out your copyright notice in the Description page of Project Settings.
#include "CoreMinimal.h"
#include "PyLink.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "GameFramework/GameModeBase.h"
#include "PyLinkGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UEPYLINK_API APyLinkGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPyBroadcast, const FString &, Name, const FString &, Data);

	UPROPERTY(BlueprintAssignable, Category = "PyLink")
	FPyBroadcast OnPyBroadcast;

	UFUNCTION(BlueprintCallable, Category = "PyLink")
	FString CallPython(const FString &Function, const FString &Arg);

	// Name of Python module to load.  E.g., 'mymodule'
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModuleName;

	// Path to module, relative to Content directory.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ModulePath = FString(TEXT("Scripts"));

	virtual void BeginPlay() override;

private:
	PyObject *pModule;
	CPyInstance pInstance;

	void _broadcast(const FString &Name, const FString &Data);
	void _setpaths();
};
