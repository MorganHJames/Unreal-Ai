// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/SpectateAIGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpectateAIGameMode() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASpectateAIGameMode_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASpectateAIGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
// End Cross Module References
	void ASpectateAIGameMode::StaticRegisterNativesASpectateAIGameMode()
	{
	}
	UClass* Z_Construct_UClass_ASpectateAIGameMode_NoRegister()
	{
		return ASpectateAIGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASpectateAIGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpectateAIGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpectateAIGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SpectateAIGameMode.h" },
		{ "ModuleRelativePath", "Public/SpectateAIGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpectateAIGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpectateAIGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpectateAIGameMode_Statics::ClassParams = {
		&ASpectateAIGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASpectateAIGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ASpectateAIGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpectateAIGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASpectateAIGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpectateAIGameMode, 953989661);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<ASpectateAIGameMode>()
	{
		return ASpectateAIGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpectateAIGameMode(Z_Construct_UClass_ASpectateAIGameMode, &ASpectateAIGameMode::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("ASpectateAIGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpectateAIGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
