// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TPS_Project/public/TPSPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTPSPlayer() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	TPS_PROJECT_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	TPS_PROJECT_API UClass* Z_Construct_UClass_ATPSPlayer();
	TPS_PROJECT_API UClass* Z_Construct_UClass_ATPSPlayer_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TPS_Project();
// End Cross Module References
	void ATPSPlayer::StaticRegisterNativesATPSPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATPSPlayer);
	UClass* Z_Construct_UClass_ATPSPlayer_NoRegister()
	{
		return ATPSPlayer::StaticClass();
	}
	struct Z_Construct_UClass_ATPSPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_springArmComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_springArmComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tpsCamComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tpsCamComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_walkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_walkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_gunMeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_gunMeshComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bulletFactory_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_bulletFactory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sniperGunComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_sniperGunComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sniperUIFactory_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_sniperUIFactory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bulletEffectFactory_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_bulletEffectFactory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_crosshairUIFactory_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_crosshairUIFactory;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATPSPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_TPS_Project,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TPSPlayer.h" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_springArmComp_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_springArmComp = { "springArmComp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, springArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_springArmComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_springArmComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_tpsCamComp_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "//Field of View \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xd0\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
		{ "ToolTip", "Field of View \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xd0\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_tpsCamComp = { "tpsCamComp", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, tpsCamComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_tpsCamComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_tpsCamComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_walkSpeed_MetaData[] = {
		{ "Category", "PlayerSetting" },
		{ "Comment", "// \xef\xbf\xbd\xcc\xb5\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\n" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
		{ "ToolTip", "\xef\xbf\xbd\xcc\xb5\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_walkSpeed = { "walkSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, walkSpeed), METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_walkSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_walkSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_gunMeshComp_MetaData[] = {
		{ "Category", "GunMesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_gunMeshComp = { "gunMeshComp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, gunMeshComp), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_gunMeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_gunMeshComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletFactory_MetaData[] = {
		{ "Category", "BulletFactory" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletFactory = { "bulletFactory", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, bulletFactory), Z_Construct_UClass_UClass, Z_Construct_UClass_ABullet_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletFactory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletFactory_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperGunComp_MetaData[] = {
		{ "Category", "GunMesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperGunComp = { "sniperGunComp", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, sniperGunComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperGunComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperGunComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperUIFactory_MetaData[] = {
		{ "Category", "SniperUI" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperUIFactory = { "sniperUIFactory", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, sniperUIFactory), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperUIFactory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperUIFactory_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletEffectFactory_MetaData[] = {
		{ "Category", "BulletEffect" },
		{ "Comment", "// \xef\xbf\xbd\xd1\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc8\xbf\xef\xbf\xbd\xef\xbf\xbd\n" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
		{ "ToolTip", "\xef\xbf\xbd\xd1\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc8\xbf\xef\xbf\xbd\xef\xbf\xbd" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletEffectFactory = { "bulletEffectFactory", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, bulletEffectFactory), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletEffectFactory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletEffectFactory_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_crosshairUIFactory_MetaData[] = {
		{ "Category", "SniperUI" },
		{ "Comment", "// \xef\xbf\xbd\xcf\xb9\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd UI\n" },
		{ "ModuleRelativePath", "public/TPSPlayer.h" },
		{ "ToolTip", "\xef\xbf\xbd\xcf\xb9\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd UI" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_crosshairUIFactory = { "crosshairUIFactory", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ATPSPlayer, crosshairUIFactory), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_crosshairUIFactory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_crosshairUIFactory_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATPSPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_springArmComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_tpsCamComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_walkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_gunMeshComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletFactory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperGunComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_sniperUIFactory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_bulletEffectFactory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_crosshairUIFactory,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATPSPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATPSPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATPSPlayer_Statics::ClassParams = {
		&ATPSPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATPSPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATPSPlayer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATPSPlayer()
	{
		if (!Z_Registration_Info_UClass_ATPSPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATPSPlayer.OuterSingleton, Z_Construct_UClass_ATPSPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATPSPlayer.OuterSingleton;
	}
	template<> TPS_PROJECT_API UClass* StaticClass<ATPSPlayer>()
	{
		return ATPSPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATPSPlayer);
	ATPSPlayer::~ATPSPlayer() {}
	struct Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPSPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPSPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATPSPlayer, ATPSPlayer::StaticClass, TEXT("ATPSPlayer"), &Z_Registration_Info_UClass_ATPSPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATPSPlayer), 3926203480U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPSPlayer_h_3790586382(TEXT("/Script/TPS_Project"),
		Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPSPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Programming_Practice_Unreal5_TPS_Project_TPS_Project_UE5_1_1_TPS_Project_Source_TPS_Project_public_TPSPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
