// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FCCardInfo.h"
#include "CCardWidget.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API UCCardWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Card Data")
	FCCardInfo CardInfo;

	UFUNCTION(BlueprintCallable, Category = "Card Data")
	void SetCardInfo(const FCCardInfo& NewCardInfo);
	
};
