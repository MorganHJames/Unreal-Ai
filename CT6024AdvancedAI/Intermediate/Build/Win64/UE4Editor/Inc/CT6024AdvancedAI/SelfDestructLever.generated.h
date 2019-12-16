// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef CT6024ADVANCEDAI_SelfDestructLever_generated_h
#error "SelfDestructLever.generated.h already included, missing '#pragma once' in SelfDestructLever.h"
#endif
#define CT6024ADVANCEDAI_SelfDestructLever_generated_h

#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_RPC_WRAPPERS \
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


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASelfDestructLever(); \
	friend struct Z_Construct_UClass_ASelfDestructLever_Statics; \
public: \
	DECLARE_CLASS(ASelfDestructLever, ATriggerBox, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(ASelfDestructLever)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_INCLASS \
private: \
	static void StaticRegisterNativesASelfDestructLever(); \
	friend struct Z_Construct_UClass_ASelfDestructLever_Statics; \
public: \
	DECLARE_CLASS(ASelfDestructLever, ATriggerBox, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(ASelfDestructLever)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASelfDestructLever(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASelfDestructLever) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASelfDestructLever); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASelfDestructLever); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASelfDestructLever(ASelfDestructLever&&); \
	NO_API ASelfDestructLever(const ASelfDestructLever&); \
public:


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASelfDestructLever(ASelfDestructLever&&); \
	NO_API ASelfDestructLever(const ASelfDestructLever&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASelfDestructLever); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASelfDestructLever); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASelfDestructLever)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_PRIVATE_PROPERTY_OFFSET
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_12_PROLOG
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_RPC_WRAPPERS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_INCLASS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_INCLASS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CT6024ADVANCEDAI_API UClass* StaticClass<class ASelfDestructLever>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_SelfDestructLever_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
