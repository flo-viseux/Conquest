// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerPawn.h"

// Sets default values
ACPlayerPawn::ACPlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ACPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

