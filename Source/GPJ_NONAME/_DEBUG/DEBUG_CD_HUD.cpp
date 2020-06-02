// Fill out your copyright notice in the Description page of Project Settings.


#include "DEBUG_CD_HUD.h"

DEFINE_LOG_CATEGORY(DEBUGSysLog);

ADEBUG_CD_HUD::ADEBUG_CD_HUD() {
    #if WITH_IMGUI
        if (IsTemplate() && ImGuiMultiContextTickHandle.IsValid() && FImGuiModule::IsAvailable())
        {
            FImGuiModule::Get().RemoveImGuiDelegate(ImGuiMultiContextTickHandle);
            ImGuiMultiContextTickHandle.Reset();
        }
    #endif


    if (!IsRunningCommandlet())
    {
        IConsoleManager::Get().RegisterConsoleCommand
        (
            TEXT("DEBUGCOMMAND"),
            TEXT("hoge"),
            FConsoleCommandDelegate::CreateUFunction(this, TEXT("ToggleDebugHUD")),
			ECVF_Default
        );
    }
}

void ADEBUG_CD_HUD::InitializeParam() {
	DebugHudState = true;
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	ShowApplicationInfoHUD();
#endif
}

void ADEBUG_CD_HUD::BeginPlay() {
	Super::BeginPlay();

#if WITH_IMGUI
	ImGuiTickHandle = FImGuiModule::Get().AddWorldImGuiDelegate(FImGuiDelegate::CreateUObject(this, &ADEBUG_CD_HUD::ImGuiTick));
	ImGuiMultiContextTickHandle.Reset();
#endif	// WITH_IMGUI
}

void ADEBUG_CD_HUD::BeginDestroy() {
	Super::BeginDestroy();

#if WITH_IMGUI
	if (IsTemplate() && ImGuiMultiContextTickHandle.IsValid() && FImGuiModule::IsAvailable())
	{
		FImGuiModule::Get().RemoveImGuiDelegate(ImGuiMultiContextTickHandle);
		ImGuiMultiContextTickHandle.Reset();
	}
#endif // WITH_IMGUI
}

void ADEBUG_CD_HUD::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);

#if WITH_IMGUI
	FImGuiModule::Get().RemoveImGuiDelegate(ImGuiTickHandle);
#endif
}

void ADEBUG_CD_HUD::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

#if WITH_IMGUI
	/*
	ImGui::Begin("ImGui Debug Order Test");

	ImGui::Text("Actor Tick: Actor = '%ls', World = '%ls', CurrentWorld = '%ls'",
		*GetNameSafe(this), *GetNameSafe(GetWorld()), *GetNameSafe(GWorld));

	ImGui::End();
	*/
#endif // WITH_IMGUI
}

void ADEBUG_CD_HUD::ToggleDebugHUD() {
    DebugHudState = (DebugHudState == true) ? false : true;

    if(DebugHudState)
    {
        UE_LOG(DEBUGSysLog, Log, TEXT("DebugHUD Activated."));
    }
    else
    {
        UE_LOG(DEBUGSysLog, Log, TEXT("DebugHUD Deactivated."));
    }
}

#if WITH_IMGUI
    void ADEBUG_CD_HUD::ImGuiTick() {
        if (DebugHudState) {
            ShowApplicationInfoHUD();
        }
    }
    void ADEBUG_CD_HUD::ImGuiMultiContextTick() {
        return;
    }

    void ADEBUG_CD_HUD::ShowApplicationInfoHUD() {
        static bool show_app_about = true;

        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoTitleBar;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoNav;

        ImGui::SetNextWindowBgAlpha(0.3);
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("hoge", &show_app_about, window_flags);
        ImGui::Text("hoge");
        ImGui::End();
    } 
#endif