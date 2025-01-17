// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/NukeCountdown.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNukeCountdown() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ANukeCountdown_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ANukeCountdown();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ANukeCountdown::StaticRegisterNativesANukeCountdown()
	{
	}
	UClass* Z_Construct_UClass_ANukeCountdown_NoRegister()
	{
		return ANukeCountdown::StaticClass();
	}
	struct Z_Construct_UClass_ANukeCountdown_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_infoText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_infoText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_countDownText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_countDownText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_background_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_background;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANukeCountdown_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANukeCountdown_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NukeCountdown.h" },
		{ "ModuleRelativePath", "Public/NukeCountdown.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANukeCountdown_Statics::NewProp_infoText_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NukeCountdown.h" },
		{ "ToolTip", "The text that indicates what the timer indicates." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANukeCountdown_Statics::NewProp_infoText = { "infoText", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANukeCountdown, infoText), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANukeCountdown_Statics::NewProp_infoText_MetaData, ARRAY_COUNT(Z_Construct_UClass_ANukeCountdown_Statics::NewProp_infoText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANukeCountdown_Statics::NewProp_countDownText_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NukeCountdown.h" },
		{ "ToolTip", "The text that has the number indicating the time left until a rocket launch happens." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANukeCountdown_Statics::NewProp_countDownText = { "countDownText", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANukeCountdown, countDownText), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANukeCountdown_Statics::NewProp_countDownText_MetaData, ARRAY_COUNT(Z_Construct_UClass_ANukeCountdown_Statics::NewProp_countDownText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANukeCountdown_Statics::NewProp_background_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/NukeCountdown.h" },
		{ "ToolTip", "The background mesh for the bill board." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANukeCountdown_Statics::NewProp_background = { "background", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANukeCountdown, background), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANukeCountdown_Statics::NewProp_background_MetaData, ARRAY_COUNT(Z_Construct_UClass_ANukeCountdown_Statics::NewProp_background_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANukeCountdown_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANukeCountdown_Statics::NewProp_infoText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANukeCountdown_Statics::NewProp_countDownText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANukeCountdown_Statics::NewProp_background,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANukeCountdown_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANukeCountdown>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANukeCountdown_Statics::ClassParams = {
		&ANukeCountdown::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANukeCountdown_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_ANukeCountdown_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ANukeCountdown_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ANukeCountdown_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANukeCountdown()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANukeCountdown_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANukeCountdown, 3514268763);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<ANukeCountdown>()
	{
		return ANukeCountdown::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANukeCountdown(Z_Construct_UClass_ANukeCountdown, &ANukeCountdown::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("ANukeCountdown"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANukeCountdown);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
