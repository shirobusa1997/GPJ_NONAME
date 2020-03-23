// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

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

#include "ACCD_DebugActor.generated.h"

UCLASS()
class GPJ_NONAME_API AACCD_DebugActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AACCD_DebugActor();

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool ShowDebugToolHUD;
	bool ShowSystemDebugToolHUD;

#if WITH_IMGUI
	public:
		void ImGuiTick();
		static void ImGuiMultiContextTick();

		FImGuiDelegateHandle ImGuiTickHandle;
		static FImGuiDelegateHandle ImGuiMultiContextTickHnadle;
		void UpdateDebugToolHUD();
		void UpdateSystemDebugToolHUD();

	private:
		void InitializeParams();
#endif	// WITH_IMGUI
};
