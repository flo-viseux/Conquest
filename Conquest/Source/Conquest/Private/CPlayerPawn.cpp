// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerPawn.h"

// Sets default values
ACPlayerPawn::ACPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

