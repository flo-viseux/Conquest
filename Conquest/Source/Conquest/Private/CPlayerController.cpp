// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerController.h"

#include "CCell.h"

ACPlayerController::ACPlayerController()
{
}

void ACPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

ACCell* ACPlayerController::GetCellUnderMouse()
{
	FHitResult HitResult;
	if (GetHitResultUnderCursor(ECC_Visibility, false, HitResult))
	{
		return Cast<ACCell>(HitResult.GetActor());
	}
	return nullptr;
}
