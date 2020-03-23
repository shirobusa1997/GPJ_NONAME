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

#include "GPJ_ActorBase.generated.h"

UCLASS()
class GPJ_NONAME_API AGPJ_ActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGPJ_ActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
