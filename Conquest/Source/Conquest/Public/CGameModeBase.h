// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FCCell.h"
#include "CGrid.h"
#include "CCardActor.h"
#include "CGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API ACGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Deck")
	UDataTable* CardsDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Deck")
	TArray<FName> PlayersInitialDeckRowNames;

	UPROPERTY(BlueprintReadWrite, Category = "Deck")
	TArray<FCCardInfo> Player1Deck;

	UPROPERTY(BlueprintReadWrite, Category = "Deck")
	TArray<FCCardInfo> Player2Deck;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid")
	UBlueprint* GridBP;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid")
	int32 Width = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	int32 Height = 10;

	UPROPERTY(EditAnywhere, Category = "Grid")
	float CellSize = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Board")
	TArray<FCCell> CurrentBoard;

	UFUNCTION(BlueprintCallable, Category = "Board")
	FCCell& GetFCCell(int X, int Y);

	UFUNCTION(BlueprintCallable, Category = "Board")
	void InitGridElements();

	UFUNCTION(BlueprintCallable, Category = "Cells")
	TArray<FVector> InitCastleLocations();

	UFUNCTION(BlueprintCallable, Category = "Cells")
	TArray<FVector> InitObjectivesLocations();

	UPROPERTY(EditAnywhere, Category = "Card")
	TSubclassOf<ACCardActor> CardClass;

	UFUNCTION(BlueprintCallable, Category = "Card")
	void PlaceCard(FVector Location, FCCardInfo CardInfo);

	UFUNCTION(BlueprintCallable, Category = "Card")
	bool IsValidPlacement(int X, int Y);


	/*UFUNCTION(BlueprintCallable, Category = "Path")
	void FindCompletePath();

	UFUNCTION(BlueprintCallable, Category = "Path")
	void CountPathCards(FVector CastleLocation, FVector ObjectiveLocation, int& Index0Count, int& Index1Count);*/


private:
	ACGrid* Grid;

	TArray<FVector> ExcludedLocations;

	/*TArray<TPair<int, int>> VisitedCells;*/

	TArray<FVector> CastleLocations;

	TArray<FVector> ObjectivesLocations;

	/*bool DFS(FCCell& CurrentCell, FVector ObjectiveLocation, int CurrentPathIndex);

	void DFSWithCounting(FCCell& CurrentCell, FVector ObjectiveLocation, int& Index0Count, int& Index1Count);

	bool IsValidConnection(FCCell& CurrentCell, FCCell& NextCell, int PathIndex);*/
};
