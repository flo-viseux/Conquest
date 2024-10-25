// Fill out your copyright notice in the Description page of Project Settings.


#include "CCardActor.h"

// Sets default values
ACCardActor::ACCardActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACCardActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACCardActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

