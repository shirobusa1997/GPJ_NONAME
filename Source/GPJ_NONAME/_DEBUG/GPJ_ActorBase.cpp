// Fill out your copyright notice in the Description page of Project Settings.


#include "GPJ_ActorBase.h"

// Sets default values
AGPJ_ActorBase::AGPJ_ActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGPJ_ActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGPJ_ActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

