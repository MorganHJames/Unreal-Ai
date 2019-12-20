// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/Spy.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpy() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASpy_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASpy();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AHumanoid();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
// End Cross Module References
	void ASpy::StaticRegisterNativesASpy()
	{
	}
	UClass* Z_Construct_UClass_ASpy_NoRegister()
	{
		return ASpy::StaticClass();
	}
	struct Z_Construct_UClass_ASpy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHumanoid,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Spy.h" },
		{ "ModuleRelativePath", "Public/Spy.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpy_Statics::ClassParams = {
		&ASpy::StaticClass,
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
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ASpy_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ASpy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpy()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASpy_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpy, 951011899);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<ASpy>()
	{
		return ASpy::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpy(Z_Construct_UClass_ASpy, &ASpy::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("ASpy"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpy);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
