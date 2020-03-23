// Fill out your copyright notice in the Description page of Project Settings.


#include "ACCD_DebugActor.h"

// Sets default values
AACCD_DebugActor::AACCD_DebugActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	#if WITH_IMGUI
		if (IsTemplate() && ImGuiMultiContextTickHnadle.IsValid() && FImGuiModule::IsAvailable())
		{
			FImGuiModule::Get().RemoveImGuiDelegate(ImGuiMultiContextTickHnadle);
			ImGuiMultiContextTickHnadle.Reset();
		}
	#endif

	if (!IsRunningCommandlet())
	{
		IConsoleManager::Get().RegisterConsoleCommand
		(
			TEXT("hoge"),
			TEXT("hoge"),
			FConsoleCommandDelegate::CreateUFunction(this, TEXT("ShowDebugToolHUD")),
			ECVF_Default
		);
	}
}

// Called when the game starts or when spawned
void AACCD_DebugActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AACCD_DebugActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

