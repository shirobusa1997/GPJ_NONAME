// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
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
#include <ImGuiInputHandler.h>
#include <ImGuiModuleProperties.h>
#endif

#include "DEBUG_CD_HUD.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(DEBUGSysLog, Log, All);

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
		
		UFUNCTION(BlueprintCallable)
		void ToggleDebugHUD();
		void MoveForward(float AxisValue);
		void MoveRight(float AxisValue);
		void PitchCamera(float AxisValue);
		void YawCamera(float AxisValue);

		bool DebugHudState = true;

		// DebugCommand Declaration Settings
		APlayerController*  PlayerController;
		APawn*				PlayerPawn;
		UInputComponent* 	PlayerInputComponent;

		#if WITH_IMGUI
			void ImGuiTick();
			void ShowApplicationInfoHUD();
			void ShowPlayerPawnTrackerHUD();
			static void ImGuiMultiContextTick();

			FImGuiDelegateHandle ImGuiTickHandle;
			FImGuiDelegateHandle ImGuiMultiContextTickHandle;
		#endif // WITH_IMGUI

	private:
		float currentMoveForwardAxis;
		float currentMoveRightAxis;
		float currentLookUpAxis;
		float currentTurnAxis;

		FString VersionInfo;

		void InitializeParam();
};
