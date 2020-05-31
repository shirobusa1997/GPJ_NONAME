// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"

#ifdef IMGUI_API
#define WITH_IMGUI 1
#else
#define WITH_IMGUI 0
#endif	// IMGUI_API

#define GRAPHCACHESIZE 90

#if WITH_IMGUI
#include <imgui.h>
#include <ImGuiDelegates.h>
#include <ImGuiModule.h>
#endif

#include "DEBUG_CD_HUD.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GPJ_NONAME_API ADEBUG_CD_HUD : public AHUD
{
	GENERATED_BODY()

	public:
		ADEBUG_CD_HUD();
		virtual void BeginDestroy() override;
		virtual void BeginPlay() override;
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		virtual void Tick(float DeltaTime) override;
	
};
