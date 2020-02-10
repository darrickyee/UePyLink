// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UEPYLINK_PyLinkGameMode_generated_h
#error "PyLinkGameMode.generated.h already included, missing '#pragma once' in PyLinkGameMode.h"
#endif
#define UEPYLINK_PyLinkGameMode_generated_h

#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_16_DELEGATE \
struct PyLinkGameMode_eventPyBroadcast_Parms \
{ \
	FString Name; \
	FString Data; \
}; \
static inline void FPyBroadcast_DelegateWrapper(const FMulticastScriptDelegate& PyBroadcast, const FString& Name, const FString& Data) \
{ \
	PyLinkGameMode_eventPyBroadcast_Parms Parms; \
	Parms.Name=Name; \
	Parms.Data=Data; \
	PyBroadcast.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_SPARSE_DATA
#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCallPython) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Function); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->CallPython(Z_Param_Function,Z_Param_Data); \
		P_NATIVE_END; \
	}


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCallPython) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Function); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Data); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->CallPython(Z_Param_Function,Z_Param_Data); \
		P_NATIVE_END; \
	}


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPyLinkGameMode(); \
	friend struct Z_Construct_UClass_APyLinkGameMode_Statics; \
public: \
	DECLARE_CLASS(APyLinkGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UePyLink"), NO_API) \
	DECLARE_SERIALIZER(APyLinkGameMode)


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAPyLinkGameMode(); \
	friend struct Z_Construct_UClass_APyLinkGameMode_Statics; \
public: \
	DECLARE_CLASS(APyLinkGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UePyLink"), NO_API) \
	DECLARE_SERIALIZER(APyLinkGameMode)


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APyLinkGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APyLinkGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APyLinkGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APyLinkGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APyLinkGameMode(APyLinkGameMode&&); \
	NO_API APyLinkGameMode(const APyLinkGameMode&); \
public:


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APyLinkGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APyLinkGameMode(APyLinkGameMode&&); \
	NO_API APyLinkGameMode(const APyLinkGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APyLinkGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APyLinkGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APyLinkGameMode)


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_PRIVATE_PROPERTY_OFFSET
#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_10_PROLOG
#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_PRIVATE_PROPERTY_OFFSET \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_SPARSE_DATA \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_RPC_WRAPPERS \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_INCLASS \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_PRIVATE_PROPERTY_OFFSET \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_SPARSE_DATA \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_INCLASS_NO_PURE_DECLS \
	Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEPYLINK_API UClass* StaticClass<class APyLinkGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Proj424_Plugins_UePyLink_Source_UePyLink_Public_PyLinkGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
