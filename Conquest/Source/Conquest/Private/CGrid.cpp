// Fill out your copyright notice in the Description page of Project Settings.


#include "CGrid.h"
#include "CCell.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACGrid::ACGrid()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void ACGrid::GenerateGrid()
{
	TArray<AActor*> Cells;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACCell::StaticClass(), Cells);
	for(int i = Cells.Num() - 1; i >= 0; i--)
	{
		if(Cells[i])
		{
			Cells[i]->Destroy();
		}
	}
    
	GridCells.Empty();

	for (int32 X = 0; X < Width; ++X)
	{
		for (int32 Y = 0; Y < Height; ++Y)
		{
			FVector SpawnLocation = GetWorldPositionFromGridPosition(X, Y);
			FActorSpawnParameters SpawnParams;
			FRotator SpawnRotation = FRotator(0, 0, 0);
			ACCell* newCell = GetWorld()->SpawnActor<ACCell>(cellBP->GeneratedClass, SpawnLocation, SpawnRotation, SpawnParams);
			newCell->AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale);
			newCell->SetActorLocation(SpawnLocation);
			newCell->X = X;
			newCell->Y = Y;
#if WITH_EDITOR
			newCell->SetActorLabel(FString::Printf(TEXT("Cell_%d_%d"), static_cast<int>(X), static_cast<int>(Y)));
#endif
			newCell->SetActorScale3D(FVector(1, 1, 1));
			GridCells.Add((newCell));
		}
	}

	this->SetActorLocation(FVector((-Width * CellSize - CellSize) / 2, (-Height * CellSize - CellSize) / 2, 0));
}

FVector ACGrid::GetWorldPositionFromGridPosition(int32 X, int32 Y) const
{
	return GetActorLocation() + FVector(X * CellSize + CellSize, Y * CellSize + CellSize, 0.0f);
}

void ACGrid::GetGridPositionFromWorldPosition(const FVector& WorldPosition, int32& OutX, int32& OutY) const
{
	FVector LocalPosition = WorldPosition - GetActorLocation();
	OutX = FMath::FloorToInt(LocalPosition.X / CellSize);
	OutY = FMath::FloorToInt(LocalPosition.Y / CellSize);
}

bool ACGrid::IsValidGridPosition(int32 X, int32 Y) const
{
	return X >= 0 && X < Width && Y >= 0 && Y < Height;
}


