// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FCCell.h"
#include "CGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API ACGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Board")
	TArray<FCCell> CurrentBoard;
};
