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
	CT6024ADVANCEDAI_API UFunction* Z_Construct_UFunction_ASpy_OnOverlapBegin2();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	CT6024ADVANCEDAI_API UFunction* Z_Construct_UFunction_ASpy_OnOverlapEnd2();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox_NoRegister();
// End Cross Module References
	void ASpy::StaticRegisterNativesASpy()
	{
		UClass* Class = ASpy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin2", &ASpy::execOnOverlapBegin2 },
			{ "OnOverlapEnd2", &ASpy::execOnOverlapEnd2 },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics
	{
		struct Spy_eventOnOverlapBegin2_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::NewProp_a_otherActor = { "a_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Spy_eventOnOverlapBegin2_Parms, a_otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::NewProp_a_overlappedActor = { "a_overlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Spy_eventOnOverlapBegin2_Parms, a_overlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::NewProp_a_otherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::NewProp_a_overlappedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Spy.h" },
		{ "ToolTip", "Declare overlap begin function." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpy, nullptr, "OnOverlapBegin2", sizeof(Spy_eventOnOverlapBegin2_Parms), Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASpy_OnOverlapBegin2()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASpy_OnOverlapBegin2_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics
	{
		struct Spy_eventOnOverlapEnd2_Parms
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::NewProp_a_otherActor = { "a_otherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Spy_eventOnOverlapEnd2_Parms, a_otherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::NewProp_a_overlappedActor = { "a_overlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Spy_eventOnOverlapEnd2_Parms, a_overlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::NewProp_a_otherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::NewProp_a_overlappedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Spy.h" },
		{ "ToolTip", "Declare overlap end function." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpy, nullptr, "OnOverlapEnd2", sizeof(Spy_eventOnOverlapEnd2_Parms), Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASpy_OnOverlapEnd2()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASpy_OnOverlapEnd2_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASpy_NoRegister()
	{
		return ASpy::StaticClass();
	}
	struct Z_Construct_UClass_ASpy_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_startingHealthLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_startingHealthLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_startingLockerocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_startingLockerocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_guardChecker_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_guardChecker;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHumanoid,
		(UObject* (*)())Z_Construct_UPackage__Script_CT6024AdvancedAI,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASpy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpy_OnOverlapBegin2, "OnOverlapBegin2" }, // 3055817615
		{ &Z_Construct_UFunction_ASpy_OnOverlapEnd2, "OnOverlapEnd2" }, // 626502335
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Spy.h" },
		{ "ModuleRelativePath", "Public/Spy.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpy_Statics::NewProp_startingHealthLocation_MetaData[] = {
		{ "Category", "locations" },
		{ "ModuleRelativePath", "Public/Spy.h" },
		{ "ToolTip", "The first health kit that the spy can see." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpy_Statics::NewProp_startingHealthLocation = { "startingHealthLocation", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpy, startingHealthLocation), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpy_Statics::NewProp_startingHealthLocation_MetaData, ARRAY_COUNT(Z_Construct_UClass_ASpy_Statics::NewProp_startingHealthLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpy_Statics::NewProp_startingLockerocation_MetaData[] = {
		{ "Category", "locations" },
		{ "ModuleRelativePath", "Public/Spy.h" },
		{ "ToolTip", "The first locker that the spy can see." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpy_Statics::NewProp_startingLockerocation = { "startingLockerocation", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpy, startingLockerocation), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpy_Statics::NewProp_startingLockerocation_MetaData, ARRAY_COUNT(Z_Construct_UClass_ASpy_Statics::NewProp_startingLockerocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpy_Statics::NewProp_guardChecker_MetaData[] = {
		{ "Category", "References" },
		{ "ModuleRelativePath", "Public/Spy.h" },
		{ "ToolTip", "The box in which the spy can see guards looking at itself." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpy_Statics::NewProp_guardChecker = { "guardChecker", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpy, guardChecker), Z_Construct_UClass_ATriggerBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpy_Statics::NewProp_guardChecker_MetaData, ARRAY_COUNT(Z_Construct_UClass_ASpy_Statics::NewProp_guardChecker_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpy_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpy_Statics::NewProp_startingHealthLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpy_Statics::NewProp_startingLockerocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpy_Statics::NewProp_guardChecker,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpy>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpy_Statics::ClassParams = {
		&ASpy::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASpy_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ASpy_Statics::PropPointers),
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
	IMPLEMENT_CLASS(ASpy, 2532915653);
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
