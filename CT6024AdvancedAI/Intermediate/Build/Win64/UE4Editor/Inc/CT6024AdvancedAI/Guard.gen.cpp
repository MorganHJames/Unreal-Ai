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
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_chargingLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_chargingLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_healthKitLocations_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_healthKitLocations;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_healthKitLocations_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_energyText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_energyText;
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGuard_Statics::NewProp_chargingLocation_MetaData[] = {
		{ "Category", "locations" },
		{ "ModuleRelativePath", "Public/Guard.h" },
		{ "ToolTip", "The location of the charging station." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGuard_Statics::NewProp_chargingLocation = { "chargingLocation", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGuard, chargingLocation), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGuard_Statics::NewProp_chargingLocation_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGuard_Statics::NewProp_chargingLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGuard_Statics::NewProp_healthKitLocations_MetaData[] = {
		{ "Category", "locations" },
		{ "ModuleRelativePath", "Public/Guard.h" },
		{ "ToolTip", "All the locations of the health kits." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGuard_Statics::NewProp_healthKitLocations = { "healthKitLocations", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGuard, healthKitLocations), METADATA_PARAMS(Z_Construct_UClass_AGuard_Statics::NewProp_healthKitLocations_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGuard_Statics::NewProp_healthKitLocations_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGuard_Statics::NewProp_healthKitLocations_Inner = { "healthKitLocations", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGuard_Statics::NewProp_energyText_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Guard.h" },
		{ "ToolTip", "The energy indicator above the guard." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGuard_Statics::NewProp_energyText = { "energyText", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGuard, energyText), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGuard_Statics::NewProp_energyText_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGuard_Statics::NewProp_energyText_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGuard_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGuard_Statics::NewProp_chargingLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGuard_Statics::NewProp_healthKitLocations,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGuard_Statics::NewProp_healthKitLocations_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGuard_Statics::NewProp_energyText,
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
	IMPLEMENT_CLASS(AGuard, 2569858650);
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
