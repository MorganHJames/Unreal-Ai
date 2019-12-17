// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/Guard.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGuard() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AGuard_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AGuard();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AHumanoid();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
// End Cross Module References
	void AGuard::StaticRegisterNativesAGuard()
	{
	}
	UClass* Z_Construct_UClass_AGuard_NoRegister()
	{
		return AGuard::StaticClass();
	}
	struct Z_Construct_UClass_AGuard_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnergyText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EnergyText;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGuard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHumanoid,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGuard_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Guard.h" },
		{ "ModuleRelativePath", "Public/Guard.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGuard_Statics::NewProp_EnergyText_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Guard.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGuard_Statics::NewProp_EnergyText = { "EnergyText", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGuard, EnergyText), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGuard_Statics::NewProp_EnergyText_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGuard_Statics::NewProp_EnergyText_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGuard_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGuard_Statics::NewProp_EnergyText,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGuard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGuard>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGuard_Statics::ClassParams = {
		&AGuard::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGuard_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AGuard_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AGuard_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGuard_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGuard()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGuard_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGuard, 3692091660);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<AGuard>()
	{
		return AGuard::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGuard(Z_Construct_UClass_AGuard, &AGuard::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("AGuard"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGuard);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
