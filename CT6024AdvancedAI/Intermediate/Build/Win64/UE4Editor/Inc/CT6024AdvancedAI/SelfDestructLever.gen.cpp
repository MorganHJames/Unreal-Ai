// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/SelfDestructLever.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSelfDestructLever() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASelfDestructLever_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ASelfDestructLever();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
	CT6024ADVANCEDAI_API UFunction* Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ASelfDestructLever::StaticRegisterNativesASelfDestructLever()
	{
		UClass* Class = ASelfDestructLever::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &ASelfDestructLever::execOnOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics
	{
		struct SelfDestructLever_eventOnOverlapBegin_Parms
		{
			AActor* a_overlappedActor;
			AActor* a_otherActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_a_otherActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_a_overlappedActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::NewProp_a_otherActor = { "a_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SelfDestructLever_eventOnOverlapBegin_Parms, a_otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::NewProp_a_overlappedActor = { "a_overlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SelfDestructLever_eventOnOverlapBegin_Parms, a_overlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::NewProp_a_otherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::NewProp_a_overlappedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SelfDestructLever.h" },
		{ "ToolTip", "Declare overlap begin function." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASelfDestructLever, nullptr, "OnOverlapBegin", sizeof(SelfDestructLever_eventOnOverlapBegin_Parms), Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASelfDestructLever_NoRegister()
	{
		return ASelfDestructLever::StaticClass();
	}
	struct Z_Construct_UClass_ASelfDestructLever_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_triggerBox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_triggerBox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_leverBase_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_leverBase;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASelfDestructLever_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASelfDestructLever_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASelfDestructLever_OnOverlapBegin, "OnOverlapBegin" }, // 1140711529
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASelfDestructLever_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SelfDestructLever.h" },
		{ "ModuleRelativePath", "Public/SelfDestructLever.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_triggerBox_MetaData[] = {
		{ "Category", "Reference" },
		{ "ModuleRelativePath", "Public/SelfDestructLever.h" },
		{ "ToolTip", "The trigger box for the lever activation." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_triggerBox = { "triggerBox", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASelfDestructLever, triggerBox), Z_Construct_UClass_ATriggerBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_triggerBox_MetaData, ARRAY_COUNT(Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_triggerBox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_leverBase_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SelfDestructLever.h" },
		{ "ToolTip", "The base of the lever." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_leverBase = { "leverBase", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASelfDestructLever, leverBase), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_leverBase_MetaData, ARRAY_COUNT(Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_leverBase_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASelfDestructLever_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_triggerBox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASelfDestructLever_Statics::NewProp_leverBase,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASelfDestructLever_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASelfDestructLever>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASelfDestructLever_Statics::ClassParams = {
		&ASelfDestructLever::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASelfDestructLever_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ASelfDestructLever_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_ASelfDestructLever_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ASelfDestructLever_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASelfDestructLever()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASelfDestructLever_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASelfDestructLever, 4019687864);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<ASelfDestructLever>()
	{
		return ASelfDestructLever::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASelfDestructLever(Z_Construct_UClass_ASelfDestructLever, &ASelfDestructLever::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("ASelfDestructLever"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASelfDestructLever);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
