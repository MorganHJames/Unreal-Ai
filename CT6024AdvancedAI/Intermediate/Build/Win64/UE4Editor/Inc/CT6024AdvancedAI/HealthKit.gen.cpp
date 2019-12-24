// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/HealthKit.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHealthKit() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AHealthKit_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AHealthKit();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
	CT6024ADVANCEDAI_API UFunction* Z_Construct_UFunction_AHealthKit_OnHealthKitHit();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AHealthKit::StaticRegisterNativesAHealthKit()
	{
		UClass* Class = AHealthKit::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHealthKitHit", &AHealthKit::execOnHealthKitHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics
	{
		struct HealthKit_eventOnHealthKitHit_Parms
		{
			AActor* a_selfActor;
			AActor* a_otherActor;
			FVector a_normalImpulse;
			FHitResult a_hit;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_a_hit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_a_hit;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_a_normalImpulse;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_a_otherActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_a_selfActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_hit = { "a_hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HealthKit_eventOnHealthKitHit_Parms, a_hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_hit_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_hit_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_normalImpulse = { "a_normalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HealthKit_eventOnHealthKitHit_Parms, a_normalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_otherActor = { "a_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HealthKit_eventOnHealthKitHit_Parms, a_otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_selfActor = { "a_selfActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HealthKit_eventOnHealthKitHit_Parms, a_selfActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_hit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_normalImpulse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_otherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::NewProp_a_selfActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HealthKit.h" },
		{ "ToolTip", "The on hit functionality of the health kit." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHealthKit, nullptr, "OnHealthKitHit", sizeof(HealthKit_eventOnHealthKitHit_Parms), Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHealthKit_OnHealthKitHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHealthKit_OnHealthKitHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHealthKit_NoRegister()
	{
		return AHealthKit::StaticClass();
	}
	struct Z_Construct_UClass_AHealthKit_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_verticalMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_verticalMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_horizontalMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_horizontalMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHealthKit_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AHealthKit_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHealthKit_OnHealthKitHit, "OnHealthKitHit" }, // 1873465954
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthKit_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HealthKit.h" },
		{ "ModuleRelativePath", "Public/HealthKit.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthKit_Statics::NewProp_verticalMesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HealthKit.h" },
		{ "ToolTip", "The vertical part of the health kit." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthKit_Statics::NewProp_verticalMesh = { "verticalMesh", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHealthKit, verticalMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHealthKit_Statics::NewProp_verticalMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHealthKit_Statics::NewProp_verticalMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthKit_Statics::NewProp_horizontalMesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HealthKit.h" },
		{ "ToolTip", "The horizontal part of the health kit." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthKit_Statics::NewProp_horizontalMesh = { "horizontalMesh", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHealthKit, horizontalMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHealthKit_Statics::NewProp_horizontalMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHealthKit_Statics::NewProp_horizontalMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHealthKit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthKit_Statics::NewProp_verticalMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthKit_Statics::NewProp_horizontalMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHealthKit_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHealthKit>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHealthKit_Statics::ClassParams = {
		&AHealthKit::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AHealthKit_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AHealthKit_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AHealthKit_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHealthKit_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHealthKit()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHealthKit_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHealthKit, 2713758379);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<AHealthKit>()
	{
		return AHealthKit::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHealthKit(Z_Construct_UClass_AHealthKit, &AHealthKit::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("AHealthKit"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHealthKit);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
