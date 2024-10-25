// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCardActor.h"
#include "CCell.generated.h"

UCLASS()
class CONQUEST_API ACCell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACCell();

    UPROPERTY(EditAnywhere, Category = "Grid")
	int32 X;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Y;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cards")
    ACCardActor* Card;
};
