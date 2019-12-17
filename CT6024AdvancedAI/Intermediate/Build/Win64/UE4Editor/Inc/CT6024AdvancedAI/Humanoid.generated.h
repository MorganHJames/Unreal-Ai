// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef CT6024ADVANCEDAI_Humanoid_generated_h
#error "Humanoid.generated.h already included, missing '#pragma once' in Humanoid.h"
#endif
#define CT6024ADVANCEDAI_Humanoid_generated_h

#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHumanoid(); \
	friend struct Z_Construct_UClass_AHumanoid_Statics; \
public: \
	DECLARE_CLASS(AHumanoid, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AHumanoid)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAHumanoid(); \
	friend struct Z_Construct_UClass_AHumanoid_Statics; \
public: \
	DECLARE_CLASS(AHumanoid, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AHumanoid)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHumanoid(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHumanoid) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHumanoid); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHumanoid); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHumanoid(AHumanoid&&); \
	NO_API AHumanoid(const AHumanoid&); \
public:


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHumanoid(AHumanoid&&); \
	NO_API AHumanoid(const AHumanoid&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHumanoid); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHumanoid); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHumanoid)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BulletClass() { return STRUCT_OFFSET(AHumanoid, BulletClass); } \
	FORCEINLINE static uint32 __PPO__HealthText() { return STRUCT_OFFSET(AHumanoid, HealthText); } \
	FORCEINLINE static uint32 __PPO__VisionBox() { return STRUCT_OFFSET(AHumanoid, VisionBox); }


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_9_PROLOG
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_RPC_WRAPPERS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_INCLASS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_INCLASS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CT6024ADVANCEDAI_API UClass* StaticClass<class AHumanoid>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Humanoid_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
