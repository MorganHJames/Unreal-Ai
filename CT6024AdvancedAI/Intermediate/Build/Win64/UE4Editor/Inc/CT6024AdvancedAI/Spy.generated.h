// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef CT6024ADVANCEDAI_Spy_generated_h
#error "Spy.generated.h already included, missing '#pragma once' in Spy.h"
#endif
#define CT6024ADVANCEDAI_Spy_generated_h

#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd2) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd2(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin2) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin2(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd2) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd2(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin2) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_a_overlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_a_otherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin2(Z_Param_a_overlappedActor,Z_Param_a_otherActor); \
		P_NATIVE_END; \
	}


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpy(); \
	friend struct Z_Construct_UClass_ASpy_Statics; \
public: \
	DECLARE_CLASS(ASpy, AHumanoid, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(ASpy)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_INCLASS \
private: \
	static void StaticRegisterNativesASpy(); \
	friend struct Z_Construct_UClass_ASpy_Statics; \
public: \
	DECLARE_CLASS(ASpy, AHumanoid, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(ASpy)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpy(ASpy&&); \
	NO_API ASpy(const ASpy&); \
public:


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpy() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpy(ASpy&&); \
	NO_API ASpy(const ASpy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpy)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__guardChecker() { return STRUCT_OFFSET(ASpy, guardChecker); } \
	FORCEINLINE static uint32 __PPO__startingLockerocation() { return STRUCT_OFFSET(ASpy, startingLockerocation); } \
	FORCEINLINE static uint32 __PPO__startingHealthLocation() { return STRUCT_OFFSET(ASpy, startingHealthLocation); }


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_19_PROLOG
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_RPC_WRAPPERS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_INCLASS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_INCLASS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CT6024ADVANCEDAI_API UClass* StaticClass<class ASpy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Spy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
