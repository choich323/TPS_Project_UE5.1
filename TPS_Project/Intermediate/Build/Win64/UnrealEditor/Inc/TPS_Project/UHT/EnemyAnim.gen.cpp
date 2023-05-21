// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TPS_Project/public/EnemyAnim.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyAnim() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	TPS_PROJECT_API UClass* Z_Construct_UClass_UEnemyAnim();
	TPS_PROJECT_API UClass* Z_Construct_UClass_UEnemyAnim_NoRegister();
	TPS_PROJECT_API UEnum* Z_Construct_UEnum_TPS_Project_EEnemyState();
	UPackage* Z_Construct_UPackage__Script_TPS_Project();
// End Cross Module References
	DEFINE_FUNCTION(UEnemyAnim::execOnEndAttackAnimation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnEndAttackAnimation();
		P_NATIVE_END;
	}
	struct EnemyAnim_eventPlayDamageAnim_Parms
	{
		FName sectionName;
	};
	static FName NAME_UEnemyAnim_PlayDamageAnim = FName(TEXT("PlayDamageAnim"));
	void UEnemyAnim::PlayDamageAnim(FName sectionName)
	{
		EnemyAnim_eventPlayDamageAnim_Parms Parms;
		Parms.sectionName=sectionName;
		ProcessEvent(FindFunctionChecked(NAME_UEnemyAnim_PlayDamageAnim),&Parms);
	}
	void UEnemyAnim::StaticRegisterNativesUEnemyAnim()
	{
		UClass* Class = UEnemyAnim::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnEndAttackAnimation", &UEnemyAnim::execOnEndAttackAnimation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "FSMEvent" },
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd\n" },
		{ "ModuleRelativePath", "public/EnemyAnim.h" },
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnim, nullptr, "OnEndAttackAnimation", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_sectionName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::NewProp_sectionName = { "sectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(EnemyAnim_eventPlayDamageAnim_Parms, sectionName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::NewProp_sectionName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::Function_MetaDataParams[] = {
		{ "Category", "FSMEvent" },
		{ "Comment", "// \xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd\n" },
		{ "ModuleRelativePath", "public/EnemyAnim.h" },
		{ "ToolTip", "\xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnim, nullptr, "PlayDamageAnim", nullptr, nullptr, sizeof(EnemyAnim_eventPlayDamageAnim_Parms), Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEnemyAnim);
	UClass* Z_Construct_UClass_UEnemyAnim_NoRegister()
	{
		return UEnemyAnim::StaticClass();
	}
	struct Z_Construct_UClass_UEnemyAnim_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_animState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_animState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_animState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAttackPlay_MetaData[];
#endif
		static void NewProp_bAttackPlay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackPlay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDieDone_MetaData[];
#endif
		static void NewProp_bDieDone_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDieDone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEnemyAnim_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_TPS_Project,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UEnemyAnim_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation, "OnEndAttackAnimation" }, // 3737323648
		{ &Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim, "PlayDamageAnim" }, // 360116655
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "EnemyAnim.h" },
		{ "ModuleRelativePath", "public/EnemyAnim.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_animState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::NewProp_animState_MetaData[] = {
		{ "Category", "FSM" },
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
		{ "ModuleRelativePath", "public/EnemyAnim.h" },
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_animState = { "animState", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UEnemyAnim, animState), Z_Construct_UEnum_TPS_Project_EEnemyState, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_animState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_animState_MetaData)) }; // 3226942326
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_MetaData[] = {
		{ "Category", "FSM" },
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
		{ "ModuleRelativePath", "public/EnemyAnim.h" },
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
	};
#endif
	void Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_SetBit(void* Obj)
	{
		((UEnemyAnim*)Obj)->bAttackPlay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay = { "bAttackPlay", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UEnemyAnim), &Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_MetaData[] = {
		{ "Category", "FSM" },
		{ "ModuleRelativePath", "public/EnemyAnim.h" },
	};
#endif
	void Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_SetBit(void* Obj)
	{
		((UEnemyAnim*)Obj)->bDieDone = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone = { "bDieDone", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UEnemyAnim), &Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyAnim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_animState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_animState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEnemyAnim_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyAnim>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEnemyAnim_Statics::ClassParams = {
		&UEnemyAnim::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEnemyAnim_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UEnemyAnim_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEnemyAnim()
	{
		if (!Z_Registration_Info_UClass_UEnemyAnim.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEnemyAnim.OuterSingleton, Z_Construct_UClass_UEnemyAnim_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEnemyAnim.OuterSingleton;
	}
	template<> TPS_PROJECT_API UClass* StaticClass<UEnemyAnim>()
	{
		return UEnemyAnim::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyAnim);
	UEnemyAnim::~UEnemyAnim() {}
	struct Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_EnemyAnim_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_EnemyAnim_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyAnim, UEnemyAnim::StaticClass, TEXT("UEnemyAnim"), &Z_Registration_Info_UClass_UEnemyAnim, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyAnim), 2304443223U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_EnemyAnim_h_10343910(TEXT("/Script/TPS_Project"),
		Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_EnemyAnim_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_EnemyAnim_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
