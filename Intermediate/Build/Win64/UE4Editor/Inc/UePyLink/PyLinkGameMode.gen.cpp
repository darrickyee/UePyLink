// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UePyLink/Public/PyLinkGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePyLinkGameMode() {}
// Cross Module References
	UEPYLINK_API UFunction* Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature();
	UEPYLINK_API UClass* Z_Construct_UClass_APyLinkGameMode();
	UEPYLINK_API UClass* Z_Construct_UClass_APyLinkGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_UePyLink();
	UEPYLINK_API UFunction* Z_Construct_UFunction_APyLinkGameMode_CallPython();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics
	{
		struct PyLinkGameMode_eventPyBroadcast_Parms
		{
			FString Name;
			FString Data;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Data;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyLinkGameMode_eventPyBroadcast_Parms, Data), METADATA_PARAMS(Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Data_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Data_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyLinkGameMode_eventPyBroadcast_Parms, Name), METADATA_PARAMS(Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Name_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Data,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::NewProp_Name,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PyLinkGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APyLinkGameMode, nullptr, "PyBroadcast__DelegateSignature", nullptr, nullptr, sizeof(PyLinkGameMode_eventPyBroadcast_Parms), Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void APyLinkGameMode::StaticRegisterNativesAPyLinkGameMode()
	{
		UClass* Class = APyLinkGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CallPython", &APyLinkGameMode::execCallPython },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics
	{
		struct PyLinkGameMode_eventCallPython_Parms
		{
			FString Function;
			FString Data;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Data;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Function;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyLinkGameMode_eventCallPython_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyLinkGameMode_eventCallPython_Parms, Data), METADATA_PARAMS(Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Data_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Data_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Function_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Function = { "Function", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PyLinkGameMode_eventCallPython_Parms, Function), METADATA_PARAMS(Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Function_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Function_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Data,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::NewProp_Function,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PyLinkGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APyLinkGameMode, nullptr, "CallPython", nullptr, nullptr, sizeof(PyLinkGameMode_eventCallPython_Parms), Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APyLinkGameMode_CallPython()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APyLinkGameMode_CallPython_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APyLinkGameMode_NoRegister()
	{
		return APyLinkGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APyLinkGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModulePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ModulePath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModuleName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ModuleName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnPyBroadcast_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPyBroadcast;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APyLinkGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UePyLink,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APyLinkGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APyLinkGameMode_CallPython, "CallPython" }, // 2460886952
		{ &Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature, "PyBroadcast__DelegateSignature" }, // 2711443026
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APyLinkGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PyLinkGameMode.h" },
		{ "ModuleRelativePath", "Public/PyLinkGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModulePath_MetaData[] = {
		{ "Category", "PyLinkGameMode" },
		{ "ModuleRelativePath", "Public/PyLinkGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModulePath = { "ModulePath", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APyLinkGameMode, ModulePath), METADATA_PARAMS(Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModulePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModulePath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModuleName_MetaData[] = {
		{ "Category", "PyLinkGameMode" },
		{ "ModuleRelativePath", "Public/PyLinkGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModuleName = { "ModuleName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APyLinkGameMode, ModuleName), METADATA_PARAMS(Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModuleName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModuleName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_OnPyBroadcast_MetaData[] = {
		{ "ModuleRelativePath", "Public/PyLinkGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_OnPyBroadcast = { "OnPyBroadcast", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APyLinkGameMode, OnPyBroadcast), Z_Construct_UDelegateFunction_APyLinkGameMode_PyBroadcast__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_OnPyBroadcast_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_OnPyBroadcast_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APyLinkGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModulePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_ModuleName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APyLinkGameMode_Statics::NewProp_OnPyBroadcast,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APyLinkGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APyLinkGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APyLinkGameMode_Statics::ClassParams = {
		&APyLinkGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APyLinkGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APyLinkGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_APyLinkGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APyLinkGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APyLinkGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APyLinkGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APyLinkGameMode, 2805397924);
	template<> UEPYLINK_API UClass* StaticClass<APyLinkGameMode>()
	{
		return APyLinkGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APyLinkGameMode(Z_Construct_UClass_APyLinkGameMode, &APyLinkGameMode::StaticClass, TEXT("/Script/UePyLink"), TEXT("APyLinkGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APyLinkGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
