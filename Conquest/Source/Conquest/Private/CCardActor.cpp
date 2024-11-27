// Fill out your copyright notice in the Description page of Project Settings.


#include "CCardActor.h"
#include <Net/UnrealNetwork.h>

// Sets default values
ACCardActor::ACCardActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void ACCardActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACCardActor, CardInfo);
}

void ACCardActor::SetCardInfo(const FCCardInfo& NewCardInfo)
{
	CardInfo = NewCardInfo;
}

