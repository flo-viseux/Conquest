// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCardActor.h"
#include "GameFramework/Actor.h"
#include "CCellActor.generated.h"

UCLASS()
class CONQUEST_API ACCellActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACCellActor();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnIndexChanged(int32 PlayerIndex);
	
	UFUNCTION(BlueprintCallable)
	void OnIndexChanged(int32 PlayerIndex);

    UPROPERTY(EditAnywhere, Category = "Grid")
	int32 X;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
	ACCardActor* Card;
};
