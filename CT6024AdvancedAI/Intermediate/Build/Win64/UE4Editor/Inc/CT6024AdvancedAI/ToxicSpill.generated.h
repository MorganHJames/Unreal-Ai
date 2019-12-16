// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef CT6024ADVANCEDAI_ToxicSpill_generated_h
#error "ToxicSpill.generated.h already included, missing '#pragma once' in ToxicSpill.h"
#endif
#define CT6024ADVANCEDAI_ToxicSpill_generated_h

#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_RPC_WRAPPERS \
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


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAToxicSpill(); \
	friend struct Z_Construct_UClass_AToxicSpill_Statics; \
public: \
	DECLARE_CLASS(AToxicSpill, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AToxicSpill)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAToxicSpill(); \
	friend struct Z_Construct_UClass_AToxicSpill_Statics; \
public: \
	DECLARE_CLASS(AToxicSpill, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AToxicSpill)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AToxicSpill(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AToxicSpill) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AToxicSpill); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AToxicSpill); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AToxicSpill(AToxicSpill&&); \
	NO_API AToxicSpill(const AToxicSpill&); \
public:


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AToxicSpill(AToxicSpill&&); \
	NO_API AToxicSpill(const AToxicSpill&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AToxicSpill); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AToxicSpill); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AToxicSpill)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TriggerBox() { return STRUCT_OFFSET(AToxicSpill, TriggerBox); } \
	FORCEINLINE static uint32 __PPO__ToxicSpill() { return STRUCT_OFFSET(AToxicSpill, ToxicSpill); } \
	FORCEINLINE static uint32 __PPO__BarrelOfToxicWaste() { return STRUCT_OFFSET(AToxicSpill, BarrelOfToxicWaste); }


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_9_PROLOG
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_RPC_WRAPPERS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_INCLASS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_INCLASS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CT6024ADVANCEDAI_API UClass* StaticClass<class AToxicSpill>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_ToxicSpill_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
