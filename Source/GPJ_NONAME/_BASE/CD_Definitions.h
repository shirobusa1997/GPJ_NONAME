// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CD_Definitions.generated.h"

UENUM(BlueprintType)
enum class EAppChannel : uint8
{
	EAC_Development	UMETA(DisplayName = "Dev"),
	EAC_Test		UMETA(DisplayName = "Test"),
	EAC_Release		UMETA(DisplayName = "Release")
}

USTRUCT(BlueprintType)
struct GPJ_NONAME_API FAppInternalInfo
{
	GENERATED_USTRUCT_BODY()

	public:
		UPROPERTY(BlueprintReadOnly) EAppChannel AppChannel;
		UPROPERTY(BlueprintReadOnly) FString 	 ProjectName;
		UPROPERTY(BlueprintReadOnly) FString 	 AppVersion;
		UPROPRETY(BlueprintReadOnly) FString 	 AppBuildDate;
}

class GPJ_NONAME_API CD_Definitions
{
public:
	CD_Definitions();
	~CD_Definitions();
};
