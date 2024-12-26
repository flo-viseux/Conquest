// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCardActor.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACPlayerController();

	virtual void BeginPlay() override;

	
protected:
	UFUNCTION(BlueprintCallable, Category = "Input")
	ACCellActor* GetCellUnderMouse();

	
	UFUNCTION(BlueprintCallable, Category = "Input")
	ACCardActor* GetCardUnderMouse();
	
};
