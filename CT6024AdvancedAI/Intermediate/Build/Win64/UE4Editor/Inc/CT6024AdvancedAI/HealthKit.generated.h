// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FVector;
struct FHitResult;
#ifdef CT6024ADVANCEDAI_HealthKit_generated_h
#error "HealthKit.generated.h already included, missing '#pragma once' in HealthKit.h"
#endif
#define CT6024ADVANCEDAI_HealthKit_generated_h

#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHealthKitHit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_selfActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_GET_STRUCT(FVector,Z_Param_a_normalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_a_hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHealthKitHit(Z_Param_a_selfActor,Z_Param_a_otherActor,Z_Param_a_normalImpulse,Z_Param_Out_a_hit); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHealthKitHit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_selfActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_GET_STRUCT(FVector,Z_Param_a_normalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_a_hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHealthKitHit(Z_Param_a_selfActor,Z_Param_a_otherActor,Z_Param_a_normalImpulse,Z_Param_Out_a_hit); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHealthKit(); \
	friend struct Z_Construct_UClass_AHealthKit_Statics; \
public: \
	DECLARE_CLASS(AHealthKit, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AHealthKit)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_INCLASS \
private: \
	static void StaticRegisterNativesAHealthKit(); \
	friend struct Z_Construct_UClass_AHealthKit_Statics; \
public: \
	DECLARE_CLASS(AHealthKit, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AHealthKit)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHealthKit(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHealthKit) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHealthKit); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHealthKit); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHealthKit(AHealthKit&&); \
	NO_API AHealthKit(const AHealthKit&); \
public:


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHealthKit(AHealthKit&&); \
	NO_API AHealthKit(const AHealthKit&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHealthKit); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHealthKit); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHealthKit)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__horizontalMesh() { return STRUCT_OFFSET(AHealthKit, horizontalMesh); } \
	FORCEINLINE static uint32 __PPO__verticalMesh() { return STRUCT_OFFSET(AHealthKit, verticalMesh); }


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_14_PROLOG
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_RPC_WRAPPERS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_INCLASS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_INCLASS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CT6024ADVANCEDAI_API UClass* StaticClass<class AHealthKit>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_HealthKit_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
