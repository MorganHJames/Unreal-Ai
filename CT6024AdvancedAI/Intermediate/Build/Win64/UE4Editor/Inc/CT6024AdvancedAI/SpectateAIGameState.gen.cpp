// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/SpectateAIGameState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpectateAIGameState() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASpectateAIGameState_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASpectateAIGameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameState();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
// End Cross Module References
	void ASpectateAIGameState::StaticRegisterNativesASpectateAIGameState()
	{
	}
	UClass* Z_Construct_UClass_ASpectateAIGameState_NoRegister()
	{
		return ASpectateAIGameState::StaticClass();
	}
	struct Z_Construct_UClass_ASpectateAIGameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpectateAIGameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameState,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpectateAIGameState_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SpectateAIGameState.h" },
		{ "ModuleRelativePath", "Public/SpectateAIGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpectateAIGameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpectateAIGameState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpectateAIGameState_Statics::ClassParams = {
		&ASpectateAIGameState::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_ASpectateAIGameState_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ASpectateAIGameState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpectateAIGameState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASpectateAIGameState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpectateAIGameState, 3238491297);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<ASpectateAIGameState>()
	{
		return ASpectateAIGameState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpectateAIGameState(Z_Construct_UClass_ASpectateAIGameState, &ASpectateAIGameState::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("ASpectateAIGameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpectateAIGameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
