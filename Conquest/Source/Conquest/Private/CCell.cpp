// Fill out your copyright notice in the Description page of Project Settings.


#include "CCell.h"

// Sets default values
ACCell::ACCell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}
