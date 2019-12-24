// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/GameController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameController() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AGameController_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AGameController();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ANukeCountdown_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor_NoRegister();
// End Cross Module References
	void AGameController::StaticRegisterNativesAGameController()
	{
	}
	UClass* Z_Construct_UClass_AGameController_NoRegister()
	{
		return AGameController::StaticClass();
	}
	struct Z_Construct_UClass_AGameController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_countDownBillboard_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_countDownBillboard;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_lever_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_lever;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rocket_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_rocket;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GameController.h" },
		{ "ModuleRelativePath", "Public/GameController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameController_Statics::NewProp_countDownBillboard_MetaData[] = {
		{ "Category", "References" },
		{ "ModuleRelativePath", "Public/GameController.h" },
		{ "ToolTip", "The count down billboard." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameController_Statics::NewProp_countDownBillboard = { "countDownBillboard", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameController, countDownBillboard), Z_Construct_UClass_ANukeCountdown_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameController_Statics::NewProp_countDownBillboard_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameController_Statics::NewProp_countDownBillboard_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameController_Statics::NewProp_lever_MetaData[] = {
		{ "Category", "References" },
		{ "ModuleRelativePath", "Public/GameController.h" },
		{ "ToolTip", "The lever the spy needs to pull." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameController_Statics::NewProp_lever = { "lever", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameController, lever), Z_Construct_UClass_AStaticMeshActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameController_Statics::NewProp_lever_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameController_Statics::NewProp_lever_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameController_Statics::NewProp_rocket_MetaData[] = {
		{ "Category", "References" },
		{ "ModuleRelativePath", "Public/GameController.h" },
		{ "ToolTip", "The rocket." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameController_Statics::NewProp_rocket = { "rocket", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameController, rocket), Z_Construct_UClass_AStaticMeshActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameController_Statics::NewProp_rocket_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameController_Statics::NewProp_rocket_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameController_Statics::NewProp_countDownBillboard,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameController_Statics::NewProp_lever,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameController_Statics::NewProp_rocket,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameController_Statics::ClassParams = {
		&AGameController::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGameController_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AGameController_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AGameController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGameController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameController, 3696785601);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<AGameController>()
	{
		return AGameController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameController(Z_Construct_UClass_AGameController, &AGameController::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("AGameController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
