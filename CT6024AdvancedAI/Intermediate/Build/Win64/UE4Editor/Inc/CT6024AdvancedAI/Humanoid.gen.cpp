// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CT6024AdvancedAI/Public/Humanoid.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHumanoid() {}
// Cross Module References
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AHumanoid_NoRegister();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_AHumanoid();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_CT6024AdvancedAI();
	CT6024ADVANCEDAI_API UFunction* Z_Construct_UFunction_AHumanoid_OnOverlapBegin();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	CT6024ADVANCEDAI_API UFunction* Z_Construct_UFunction_AHumanoid_OnOverlapEnd();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	CT6024ADVANCEDAI_API UClass* Z_Construct_UClass_ABullet_NoRegister();
// End Cross Module References
	void AHumanoid::StaticRegisterNativesAHumanoid()
	{
		UClass* Class = AHumanoid::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &AHumanoid::execOnOverlapBegin },
			{ "OnOverlapEnd", &AHumanoid::execOnOverlapEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics
	{
		struct Humanoid_eventOnOverlapBegin_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::NewProp_a_otherActor = { "a_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Humanoid_eventOnOverlapBegin_Parms, a_otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::NewProp_a_overlappedActor = { "a_overlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Humanoid_eventOnOverlapBegin_Parms, a_overlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::NewProp_a_otherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::NewProp_a_overlappedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Humanoid.h" },
		{ "ToolTip", "Declare overlap begin function." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHumanoid, nullptr, "OnOverlapBegin", sizeof(Humanoid_eventOnOverlapBegin_Parms), Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHumanoid_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHumanoid_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics
	{
		struct Humanoid_eventOnOverlapEnd_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::NewProp_a_otherActor = { "a_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Humanoid_eventOnOverlapEnd_Parms, a_otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::NewProp_a_overlappedActor = { "a_overlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Humanoid_eventOnOverlapEnd_Parms, a_overlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::NewProp_a_otherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::NewProp_a_overlappedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Humanoid.h" },
		{ "ToolTip", "Declare overlap end function." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHumanoid, nullptr, "OnOverlapEnd", sizeof(Humanoid_eventOnOverlapEnd_Parms), Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHumanoid_OnOverlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHumanoid_OnOverlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHumanoid_NoRegister()
	{
		return AHumanoid::StaticClass();
	}
	struct Z_Construct_UClass_AHumanoid_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_visionBox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_visionBox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_locations_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_locations;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_locations_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_healthText_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_healthText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_actorsSeen_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_actorsSeen;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_actorsSeen_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bulletClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_bulletClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHumanoid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AHumanoid_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHumanoid_OnOverlapBegin, "OnOverlapBegin" }, // 3663817632
		{ &Z_Construct_UFunction_AHumanoid_OnOverlapEnd, "OnOverlapEnd" }, // 2423795595
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHumanoid_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Humanoid.h" },
		{ "ModuleRelativePath", "Public/Humanoid.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHumanoid_Statics::NewProp_visionBox_MetaData[] = {
		{ "Category", "References" },
		{ "ModuleRelativePath", "Public/Humanoid.h" },
		{ "ToolTip", "A reference to the vision box that humanoid should use for it's vision." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHumanoid_Statics::NewProp_visionBox = { "visionBox", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHumanoid, visionBox), Z_Construct_UClass_ATriggerBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHumanoid_Statics::NewProp_visionBox_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHumanoid_Statics::NewProp_visionBox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHumanoid_Statics::NewProp_locations_MetaData[] = {
		{ "Category", "locations" },
		{ "ModuleRelativePath", "Public/Humanoid.h" },
		{ "ToolTip", "The locations that the humanoid can wander to." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AHumanoid_Statics::NewProp_locations = { "locations", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHumanoid, locations), METADATA_PARAMS(Z_Construct_UClass_AHumanoid_Statics::NewProp_locations_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHumanoid_Statics::NewProp_locations_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHumanoid_Statics::NewProp_locations_Inner = { "locations", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHumanoid_Statics::NewProp_healthText_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Humanoid.h" },
		{ "ToolTip", "The text that indicates the humanoids current health above it's head." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHumanoid_Statics::NewProp_healthText = { "healthText", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHumanoid, healthText), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHumanoid_Statics::NewProp_healthText_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHumanoid_Statics::NewProp_healthText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHumanoid_Statics::NewProp_actorsSeen_MetaData[] = {
		{ "Category", "References" },
		{ "ModuleRelativePath", "Public/Humanoid.h" },
		{ "ToolTip", "The actors that the humanoid has seen." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AHumanoid_Statics::NewProp_actorsSeen = { "actorsSeen", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHumanoid, actorsSeen), METADATA_PARAMS(Z_Construct_UClass_AHumanoid_Statics::NewProp_actorsSeen_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHumanoid_Statics::NewProp_actorsSeen_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHumanoid_Statics::NewProp_actorsSeen_Inner = { "actorsSeen", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHumanoid_Statics::NewProp_bulletClass_MetaData[] = {
		{ "Category", "Shooting" },
		{ "ModuleRelativePath", "Public/Humanoid.h" },
		{ "ToolTip", "The bullet to spawn in front of the humanoid." },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AHumanoid_Statics::NewProp_bulletClass = { "bulletClass", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHumanoid, bulletClass), Z_Construct_UClass_ABullet_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AHumanoid_Statics::NewProp_bulletClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AHumanoid_Statics::NewProp_bulletClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHumanoid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHumanoid_Statics::NewProp_visionBox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHumanoid_Statics::NewProp_locations,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHumanoid_Statics::NewProp_locations_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHumanoid_Statics::NewProp_healthText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHumanoid_Statics::NewProp_actorsSeen,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHumanoid_Statics::NewProp_actorsSeen_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHumanoid_Statics::NewProp_bulletClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHumanoid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHumanoid>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHumanoid_Statics::ClassParams = {
		&AHumanoid::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AHumanoid_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AHumanoid_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AHumanoid_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHumanoid_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHumanoid()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHumanoid_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHumanoid, 2171762169);
	template<> CT6024ADVANCEDAI_API UClass* StaticClass<AHumanoid>()
	{
		return AHumanoid::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHumanoid(Z_Construct_UClass_AHumanoid, &AHumanoid::StaticClass, TEXT("/Script/CT6024AdvancedAI"), TEXT("AHumanoid"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHumanoid);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
