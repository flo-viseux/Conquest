// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FCCardInfo.h"
#include "GameFramework/Actor.h"
#include "CCardActor.generated.h"

UCLASS()
class CONQUEST_API ACCardActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACCardActor();
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "Card Data")
	FCCardInfo CardInfo;

	UFUNCTION(BlueprintCallable, Category = "Card Data")
	void SetCardInfo(const FCCardInfo& NewCardInfo);

};
