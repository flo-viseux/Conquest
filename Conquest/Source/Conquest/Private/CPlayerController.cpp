// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerController.h"
#include "CCellActor.h"

ACPlayerController::ACPlayerController()
{
}

void ACPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

ACCellActor* ACPlayerController::GetCellUnderMouse()
{
	FHitResult HitResult;
	if (GetHitResultUnderCursor(ECC_Visibility, false, HitResult))
	{
		return Cast<ACCellActor>(HitResult.GetActor());
	}
	return nullptr;
}
