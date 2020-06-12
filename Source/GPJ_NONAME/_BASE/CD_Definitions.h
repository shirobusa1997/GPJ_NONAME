// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Serialization/JsonSerializerMacros.h"
#include "CD_Definitions.generated.h"

UENUM(BlueprintType)
enum class EAppChannel : uint8
{
	EAC_Development	UMETA(DisplayName = "DEV"),
	EAC_Test		UMETA(DisplayName = "TST"),
	EAC_Release		UMETA(DisplayName = "RLS")
};

USTRUCT(BlueprintType)
struct GPJ_NONAME_API FAppInternalInfo
{
	GENERATED_USTRUCT_BODY()
	public:
		UPROPERTY(BlueprintReadWrite) EAppChannel AppChannel;
		UPROPERTY(BlueprintReadWrite) FString 	  ProjectName;
		UPROPERTY(BlueprintReadWrite) FString 	  AppVersion;
		UPROPERTY(BlueprintReadWrite) FString 	  AppBuildDate;
};

class GPJ_NONAME_API CD_Definitions
{
public:
	CD_Definitions();
	~CD_Definitions();
};
