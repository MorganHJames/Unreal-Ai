// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CT6024ADVANCEDAI_Guard_generated_h
#error "Guard.generated.h already included, missing '#pragma once' in Guard.h"
#endif
#define CT6024ADVANCEDAI_Guard_generated_h

#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_RPC_WRAPPERS
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGuard(); \
	friend struct Z_Construct_UClass_AGuard_Statics; \
public: \
	DECLARE_CLASS(AGuard, AHumanoid, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AGuard)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGuard(); \
	friend struct Z_Construct_UClass_AGuard_Statics; \
public: \
	DECLARE_CLASS(AGuard, AHumanoid, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CT6024AdvancedAI"), NO_API) \
	DECLARE_SERIALIZER(AGuard)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGuard(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGuard) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGuard); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGuard); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGuard(AGuard&&); \
	NO_API AGuard(const AGuard&); \
public:


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGuard(AGuard&&); \
	NO_API AGuard(const AGuard&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGuard); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGuard); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGuard)


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__EnergyText() { return STRUCT_OFFSET(AGuard, EnergyText); } \
	FORCEINLINE static uint32 __PPO__healthKitLocations() { return STRUCT_OFFSET(AGuard, healthKitLocations); } \
	FORCEINLINE static uint32 __PPO__ChargingLocation() { return STRUCT_OFFSET(AGuard, ChargingLocation); }


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_12_PROLOG
#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_RPC_WRAPPERS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_INCLASS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_PRIVATE_PROPERTY_OFFSET \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_INCLASS_NO_PURE_DECLS \
	CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CT6024ADVANCEDAI_API UClass* StaticClass<class AGuard>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CT6024AdvancedAI_Source_CT6024AdvancedAI_Public_Guard_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
