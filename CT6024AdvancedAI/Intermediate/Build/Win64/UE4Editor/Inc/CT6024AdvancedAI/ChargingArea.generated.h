// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef CT6024ADVANCEDAI_ChargingArea_generated_h
#error "ChargingArea.generated.h already included, missing '#pragma once' in ChargingArea.h"
#endif
#define CT6024ADVANCEDAI_ChargingArea_generated_h

#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAChargingArea(); \
	friend struct Z_Construct_UClass_AChargingArea_Statics; \
public: \
	DECLARE_CLASS(AChargingArea, ATriggerBox, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AChargingArea)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAChargingArea(); \
	friend struct Z_Construct_UClass_AChargingArea_Statics; \
public: \
	DECLARE_CLASS(AChargingArea, ATriggerBox, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AChargingArea)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AChargingArea(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AChargingArea) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AChargingArea); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AChargingArea); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AChargingArea(AChargingArea&&); \
	NO_API AChargingArea(const AChargingArea&); \
public:


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AChargingArea(AChargingArea&&); \
	NO_API AChargingArea(const AChargingArea&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AChargingArea); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AChargingArea); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AChargingArea)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_PRIVATE_PROPERTY_OFFSET
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_14_PROLOG
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_RPC_WRAPPERS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_INCLASS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_INCLASS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CT6024ADVANCEDAI_API UClass* StaticClass<class AChargingArea>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ChargingArea_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
