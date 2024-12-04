// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FCCell.h"
#include "CGrid.h"
#include "CCardActor.h"
#include "CGameModeBase.generated.h"

struct FPathInfo
{
	TArray<FVector2D> PathCells;
	int Player0Cards;
	int Player1Cards;
};

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
	bool IsValidPlacement(int X, int Y, FCCardInfo& CardInfo);


	
	UFUNCTION(BlueprintCallable, Category = "Path")
	void CheckGamePaths();

	UFUNCTION(BlueprintCallable, Category = "Path")
	FCPathInfo FindAndCountPathBetweenPoints(FVector Start, FVector End);

	UFUNCTION(BlueprintCallable, Category = "Path")
	FCPathInfo DFSPathWithPlayerCount(FVector Current, FVector End, TArray<FVector>& Visited, FCPathInfo& CurrentPathInfo);



private:
	ACGrid* Grid;

	TArray<FVector> ExcludedLocations;

	TArray<FVector> CastleLocations;

	TArray<FVector> ObjectivesLocations;
};
