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

	UFUNCTION(BlueprintImplementableEvent)
	void BP_NewObjectiveConquered(const FVector ObjectivePosition);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Deck")
	UDataTable* CardsDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Deck")
	TArray<FName> PlayersInitialDeckRowNames;

	UPROPERTY(BlueprintReadWrite, Category = "Deck")
	TArray<FCCardInfo> Player1Deck;

	UPROPERTY(BlueprintReadWrite, Category = "Deck")
	TArray<FCCardInfo> Player2Deck;
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnScoreChanged(int32 PlayerIndex);
	
	UFUNCTION(BlueprintCallable, Category = "Score")
	void IncreasePlayerScore(int32 PlayerIndex);


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid")
	TSubclassOf<ACGrid> GridBP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid")
    ACGrid* Grid;

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

	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FVector2D> XCastlePos;

	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FVector2D> YCastlePos;

	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FVector2D> ObjectivesPos1;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FVector2D> ObjectivesPos2;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FVector2D> ObjectivesPos3;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FVector2D> ObjectivesPos4;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	TArray<FVector2D> ObjectivesPos5;
	
	
	UFUNCTION(BlueprintCallable, Category = "Board")
	void InitGridElements();

	UFUNCTION(BlueprintCallable, Category = "Cells")
	void InitCastleLocations(int index);

	UFUNCTION(BlueprintCallable, Category = "Cells")
	void InitObjectivesLocations(int index);

	UPROPERTY(EditAnywhere, Category = "Card")
	TSubclassOf<ACCardActor> CardClass;

	UFUNCTION(BlueprintCallable, Category = "Card")
	void PlaceCard(FVector Location, FRotator Rotation, FCCardInfo CardInfo);

	
	UFUNCTION(BlueprintCallable, Category = "Card")
	TArray<ECLinkDirection> GetLinksWithRotation(FRotator Rotation, FCCardInfo CardInfo);

	UFUNCTION(BlueprintCallable, Category = "Card")
	bool IsValidCardPlacement(FVector Location, FRotator Rotation, FCCardInfo CardInfo);
	

	UFUNCTION(BlueprintCallable, Category = "Path")
	void CheckGamePaths();

	UFUNCTION(BlueprintCallable, Category = "Path")
	FCPathInfo FindAndCountPathBetweenPoints(FVector Start, FVector End);
	
	UFUNCTION(BlueprintCallable, Category = "Path")
	bool IsValidPathLinks(TArray<ECLinkDirection> CurrentCardLinks, TArray<ECLinkDirection> NextCardLinks, int32 CurrentCellX, int32 CurrentCellY, int32 NextCellX, int32 NextCellY);

private:
	TArray<FVector> ExcludedLocations;

	TArray<FVector> CastleLocations;

	TArray<FVector> ObjectivesLocations;
};
