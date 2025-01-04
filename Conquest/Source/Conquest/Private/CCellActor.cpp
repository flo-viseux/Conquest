// Fill out your copyright notice in the Description page of Project Settings.


#include "CCellActor.h"

// Sets default values
ACCellActor::ACCellActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void ACCellActor::OnIndexChanged(int32 PlayerIndex)
{
	BP_OnIndexChanged(PlayerIndex);
}


