// Fill out your copyright notice in the Description page of Project Settings.


#include "CGameModeBase.h"
#include "FCCardPosition.h"

void ACGameModeBase::BeginPlay()
{
	FVector SpawnLocation = FVector(0);
	FActorSpawnParameters SpawnParams;
	FRotator SpawnRotation = FRotator(0, 0, 0);
	Grid = GetWorld()->SpawnActor<ACGrid>(GridBP->GeneratedClass, SpawnLocation, SpawnRotation, SpawnParams);

	Grid->GenerateGrid(Width, Height, CellSize);

	for (int X = 0; X < Width; ++X)
	{
		for (int Y = 0; Y < Height; ++Y)
		{
			FCCell NewCell = FCCell(Grid->GetWorldPositionFromGridPosition(X, Y), X, Y, false, FCCardInfo());
			CurrentBoard.Add(NewCell);
		}
	}

	InitGridElements();
}

void ACGameModeBase::InitGridElements()
{
	for (FVector v : GetCastleLocations())
	{
		FVector SpawnLocation = v;
		FActorSpawnParameters SpawnParams;
		FRotator SpawnRotation = FRotator(0, 0, -90);
		ACCardActor* newCard = GetWorld()->SpawnActor<ACCardActor>(CardClass, SpawnLocation, SpawnRotation, SpawnParams);

		ACCellActor* Cell = Grid->GetCellFromWorldPosition(v);
		newCard->AttachToActor(Cell, FAttachmentTransformRules::SnapToTargetIncludingScale);

		TArray<ELinkDirection> NewLinks = TArray<ELinkDirection>{ ELinkDirection::Top, ELinkDirection::Bottom, ELinkDirection::Right, ELinkDirection::Left };

		FCCardInfo NewCardInfo = FCCardInfo("Castle", FLinearColor::White, NewLinks);

		GetFCCell(Cell->X, Cell->Y).bIsOccuped = true;
		GetFCCell(Cell->X, Cell->Y).CardInfo = NewCardInfo;
	}

	for (FVector v : GetObjectivesLocations())
	{
		FVector SpawnLocation = v;
		FActorSpawnParameters SpawnParams;
		FRotator SpawnRotation = FRotator(0, 0, -90);
		ACCardActor* newCard = GetWorld()->SpawnActor<ACCardActor>(CardClass, SpawnLocation, SpawnRotation, SpawnParams);

		ACCellActor* Cell = Grid->GetCellFromWorldPosition(v);
		newCard->AttachToActor(Cell, FAttachmentTransformRules::SnapToTargetIncludingScale);

		TArray<ELinkDirection> NewLinks = TArray<ELinkDirection>{ ELinkDirection::Top, ELinkDirection::Bottom, ELinkDirection::Right, ELinkDirection::Left };

		FCCardInfo NewCardInfo = FCCardInfo("Objective", FLinearColor::Gray, NewLinks);

		GetFCCell(Cell->X, Cell->Y).bIsOccuped = true;
		GetFCCell(Cell->X, Cell->Y).CardInfo = NewCardInfo;
	}
}

TArray<FVector> ACGameModeBase::GetCastleLocations()
{
	TArray<FVector> CastleLocations;

	int X = FMath::RandRange(0, Grid->Width - 1);
	int Y = FMath::RandRange(0, Grid->Height - 1);

	FVector FirstCatleLocation = Grid->GetCell(X, Y)->GetActorLocation();

	CastleLocations.Add(FirstCatleLocation);
	ExcludedLocations.Add(FirstCatleLocation);


	FVector SecondCastleLocation = FVector(0);

	if (Grid->IsValidGridPosition(X + 1, Y + 1))
		SecondCastleLocation = Grid->GetCell(X + 1, Y + 1)->GetActorLocation();
	else if (Grid->IsValidGridPosition(X - 1, Y - 1))
		SecondCastleLocation = Grid->GetCell(X - 1, Y - 1)->GetActorLocation();
	else if (Grid->IsValidGridPosition(X + 1, Y - 1))
		SecondCastleLocation = Grid->GetCell(X + 1, Y - 1)->GetActorLocation();
	else
		SecondCastleLocation = Grid->GetCell(X - 1, Y + 1)->GetActorLocation();

	ExcludedLocations.Add(SecondCastleLocation);
	CastleLocations.Add(SecondCastleLocation);

	return CastleLocations;
}

TArray<FVector> ACGameModeBase::GetObjectivesLocations()
{
	TArray<FVector> ObjectivesLocations;

	for (int i = 0; i < 5; i++)
	{
		int b = 0;

		while (b < 1)
		{
			int X = FMath::RandRange(0, Grid->Width - 1);
			int Y = FMath::RandRange(0, Grid->Height - 1);

			FVector Location = Grid->GetCell(X, Y)->GetActorLocation();

			if (!ExcludedLocations.Contains(Location))
			{
				b = 1;
				ObjectivesLocations.Add(Location);
				ExcludedLocations.Add(Location);

				if (Grid->IsValidGridPosition(X + 1, Y))
					ExcludedLocations.Add(Grid->GetCell(X + 1, Y)->GetActorLocation());

				if (Grid->IsValidGridPosition(X + 1, Y + 1))
					ExcludedLocations.Add(Grid->GetCell(X + 1, Y + 1)->GetActorLocation());

				if (Grid->IsValidGridPosition(X + 1, Y - 1))
					ExcludedLocations.Add(Grid->GetCell(X + 1, Y - 1)->GetActorLocation());

				if (Grid->IsValidGridPosition(X - 1, Y))
					ExcludedLocations.Add(Grid->GetCell(X - 1, Y)->GetActorLocation());

				if (Grid->IsValidGridPosition(X - 1, Y + 1))
					ExcludedLocations.Add(Grid->GetCell(X - 1, Y + 1)->GetActorLocation());

				if (Grid->IsValidGridPosition(X - 1, Y - 1))
					ExcludedLocations.Add(Grid->GetCell(X - 1, Y - 1)->GetActorLocation());

				if (Grid->IsValidGridPosition(X, Y + 1))
					ExcludedLocations.Add(Grid->GetCell(X, Y + 1)->GetActorLocation());

				if (Grid->IsValidGridPosition(X, Y - 1))
					ExcludedLocations.Add(Grid->GetCell(X, Y - 1)->GetActorLocation());
			}
		}
	}

	return ObjectivesLocations;
}

void ACGameModeBase::PlaceCard(FVector Location, FCCardInfo CardInfo)
{
	ACCellActor* Cell = Grid->GetCellFromWorldPosition(Location);

	if (Cell == nullptr)
		return;

	if (!IsValidPlacement(Cell->X, Cell->Y))
		return;

	FVector SpawnLocation = Location;
	FActorSpawnParameters SpawnParams;
	FRotator SpawnRotation = FRotator(0, 0, -90);
	ACCardActor* newCard = GetWorld()->SpawnActor<ACCardActor>(CardClass, SpawnLocation, SpawnRotation, SpawnParams);
	newCard->AttachToActor(Cell, FAttachmentTransformRules::SnapToTargetIncludingScale);
	
	GetFCCell(Cell->X, Cell->Y).bIsOccuped = true;
	GetFCCell(Cell->X, Cell->Y).CardInfo = CardInfo;
}

bool ACGameModeBase::IsValidPlacement(int X, int Y)
{
	if (GetFCCell(X, Y).bIsOccuped == true)
		return false;

	/// Neighbors ///
 
	if (GetFCCell(X + 1, Y).bIsOccuped == true)
		return true;

	if (GetFCCell(X - 1, Y).bIsOccuped == true)
		return true;

	if (GetFCCell(X, Y + 1).bIsOccuped == true)
		return true;

	if (GetFCCell(X, Y - 1).bIsOccuped == true)
		return true;

	return false;
}


FCCell& ACGameModeBase::GetFCCell(int X, int Y)
{
	for (FCCell& cell : CurrentBoard)
	{
		int XPos = cell.X;
		int YPos = cell.Y;

		if (XPos == X && YPos == Y)
		{
			return cell;
		}
	}

	static FCCell DefaultCell(FVector::ZeroVector, X, Y, false, FCCardInfo());
    return DefaultCell;
}
