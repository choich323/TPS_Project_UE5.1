// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TPS_Project/public/TPS_ProjectGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTPS_ProjectGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	TPS_PROJECT_API UClass* Z_Construct_UClass_ATPS_ProjectGameModeBase();
	TPS_PROJECT_API UClass* Z_Construct_UClass_ATPS_ProjectGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TPS_Project();
// End Cross Module References
	void ATPS_ProjectGameModeBase::StaticRegisterNativesATPS_ProjectGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATPS_ProjectGameModeBase);
	UClass* Z_Construct_UClass_ATPS_ProjectGameModeBase_NoRegister()
	{
		return ATPS_ProjectGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TPS_Project,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TPS_ProjectGameModeBase.h" },
		{ "ModuleRelativePath", "public/TPS_ProjectGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATPS_ProjectGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics::ClassParams = {
		&ATPS_ProjectGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATPS_ProjectGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ATPS_ProjectGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATPS_ProjectGameModeBase.OuterSingleton, Z_Construct_UClass_ATPS_ProjectGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATPS_ProjectGameModeBase.OuterSingleton;
	}
	template<> TPS_PROJECT_API UClass* StaticClass<ATPS_ProjectGameModeBase>()
	{
		return ATPS_ProjectGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATPS_ProjectGameModeBase);
	ATPS_ProjectGameModeBase::~ATPS_ProjectGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPS_ProjectGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPS_ProjectGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATPS_ProjectGameModeBase, ATPS_ProjectGameModeBase::StaticClass, TEXT("ATPS_ProjectGameModeBase"), &Z_Registration_Info_UClass_ATPS_ProjectGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATPS_ProjectGameModeBase), 875668375U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPS_ProjectGameModeBase_h_1441819485(TEXT("/Script/TPS_Project"),
		Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPS_ProjectGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPS_ProjectGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
