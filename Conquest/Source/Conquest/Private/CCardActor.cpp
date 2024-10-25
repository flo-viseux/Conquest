// Fill out your copyright notice in the Description page of Project Settings.


#include "CCardActor.h"

// Sets default values
ACCardActor::ACCardActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void ACCardActor::SetCardInfo(const FCCardInfo& NewCardInfo)
{
	CardInfo = NewCardInfo;
}

