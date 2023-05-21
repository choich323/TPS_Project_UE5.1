// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TPS_Project/public/Bullet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBullet() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	TPS_PROJECT_API UClass* Z_Construct_UClass_ABullet();
	TPS_PROJECT_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TPS_Project();
// End Cross Module References
	void ABullet::StaticRegisterNativesABullet()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABullet);
	UClass* Z_Construct_UClass_ABullet_NoRegister()
	{
		return ABullet::StaticClass();
	}
	struct Z_Construct_UClass_ABullet_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_movementComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_movementComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_collisionComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_collisionComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bodyMeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_bodyMeshComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_speed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_speed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABullet_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TPS_Project,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABullet_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Bullet.h" },
		{ "ModuleRelativePath", "public/Bullet.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABullet_Statics::NewProp_movementComp_MetaData[] = {
		{ "Category", "Movement" },
		{ "Comment", "// \xef\xbf\xbd\xdf\xbb\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "public/Bullet.h" },
		{ "ToolTip", "\xef\xbf\xbd\xdf\xbb\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABullet_Statics::NewProp_movementComp = { "movementComp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ABullet, movementComp), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABullet_Statics::NewProp_movementComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::NewProp_movementComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABullet_Statics::NewProp_collisionComp_MetaData[] = {
		{ "Category", "Collision" },
		{ "Comment", "// \xef\xbf\xbd\xe6\xb5\xb9 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "public/Bullet.h" },
		{ "ToolTip", "\xef\xbf\xbd\xe6\xb5\xb9 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABullet_Statics::NewProp_collisionComp = { "collisionComp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ABullet, collisionComp), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABullet_Statics::NewProp_collisionComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::NewProp_collisionComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABullet_Statics::NewProp_bodyMeshComp_MetaData[] = {
		{ "Category", "BodyMesh" },
		{ "Comment", "// \xef\xbf\xbd\xdc\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "public/Bullet.h" },
		{ "ToolTip", "\xef\xbf\xbd\xdc\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABullet_Statics::NewProp_bodyMeshComp = { "bodyMeshComp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ABullet, bodyMeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABullet_Statics::NewProp_bodyMeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::NewProp_bodyMeshComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABullet_Statics::NewProp_speed_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "public/Bullet.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABullet_Statics::NewProp_speed = { "speed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ABullet, speed), METADATA_PARAMS(Z_Construct_UClass_ABullet_Statics::NewProp_speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::NewProp_speed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABullet_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABullet_Statics::NewProp_movementComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABullet_Statics::NewProp_collisionComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABullet_Statics::NewProp_bodyMeshComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABullet_Statics::NewProp_speed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABullet_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABullet>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABullet_Statics::ClassParams = {
		&ABullet::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABullet_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABullet_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABullet_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABullet()
	{
		if (!Z_Registration_Info_UClass_ABullet.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABullet.OuterSingleton, Z_Construct_UClass_ABullet_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABullet.OuterSingleton;
	}
	template<> TPS_PROJECT_API UClass* StaticClass<ABullet>()
	{
		return ABullet::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABullet);
	ABullet::~ABullet() {}
	struct Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_Bullet_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_Bullet_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABullet, ABullet::StaticClass, TEXT("ABullet"), &Z_Registration_Info_UClass_ABullet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABullet), 1844761728U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_Bullet_h_921791945(TEXT("/Script/TPS_Project"),
		Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_Bullet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_TPS_Project_Source_TPS_Project_public_Bullet_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
