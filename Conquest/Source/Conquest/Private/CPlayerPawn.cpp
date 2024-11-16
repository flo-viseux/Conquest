// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayerPawn.h"

#include "CGrid.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPlayerPawn::ACPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ACPlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACGrid::StaticClass(), FoundActors);
    
	if (FoundActors.Num() > 0)
	{
		Grid = Cast<ACGrid>(FoundActors[0]);
	}

}

// Called to bind functionality to input
void ACPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<FVector> ACPlayerPawn::GetCastleLocations()
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
	else
		SecondCastleLocation = Grid->GetCell(X + 1, Y - 1)->GetActorLocation();

	ExcludedLocations.Add(SecondCastleLocation);
	CastleLocations.Add(SecondCastleLocation);

	return CastleLocations;
}

TArray<FVector> ACPlayerPawn::GetObjectivesLocations()
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

