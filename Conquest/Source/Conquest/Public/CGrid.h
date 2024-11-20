// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CCellActor.h"
#include "GameFramework/Actor.h"
#include "CGrid.generated.h"

UCLASS()
class CONQUEST_API ACGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACGrid(); 
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid")
	int32 Width = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 Height = 10;

	UPROPERTY(EditAnywhere, Category = "Grid")
	float CellSize = 100.0f;
    
	UFUNCTION(Category = "Grid")
	void GenerateGrid(int32 InWidth, int32 InHeight, float InCellSize);

	UFUNCTION(BlueprintCallable, Category = "Grid")
	FVector GetWorldPositionFromGridPosition(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	void GetGridPositionFromWorldPosition(const FVector& WorldPosition, int32& OutX, int32& OutY) const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	ACCellActor* GetCellFromWorldPosition(FVector WorldPosition) const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	bool IsValidGridPosition(int32 X, int32 Y) const;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	TSubclassOf<ACCellActor> CellClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TArray<ACCellActor*> GridCells;

	ACCellActor* GetCell(int32 X, int32 Y) const;

};
