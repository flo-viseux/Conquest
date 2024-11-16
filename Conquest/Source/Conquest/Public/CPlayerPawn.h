// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPlayerPawn.generated.h"

class ACGrid;

UCLASS()
class CONQUEST_API ACPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	ACPlayerPawn();

	virtual void BeginPlay() override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:	
	UFUNCTION(BlueprintCallable, Category="Cells")
	TArray<FVector> GetCastleLocations();
	
	UFUNCTION(BlueprintCallable, Category="Cells")
	TArray<FVector> GetObjectivesLocations();

private:
	ACGrid* Grid;
	
	TArray<FVector> ExcludedLocations;
};
