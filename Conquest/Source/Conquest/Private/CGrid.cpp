// Fill out your copyright notice in the Description page of Project Settings.


#include "CGrid.h"
#include "CCellActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACGrid::ACGrid()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

void ACGrid::GenerateGrid(int32 InWidth, int32 InHeight, float InCellSize)
{
	Width = InWidth;
	Height = InHeight;
	CellSize = InCellSize;

	TArray<AActor*> Cells;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACCellActor::StaticClass(), Cells);
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
			ACCellActor* NewCell = GetWorld()->SpawnActor<ACCellActor>(CellClass, SpawnLocation, SpawnRotation, SpawnParams);
			NewCell->AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale);
			NewCell->SetActorLocation(SpawnLocation);
			NewCell->X = X;
			NewCell->Y = Y;
			NewCell->SetActorScale3D(FVector(1, 1, 1));
			GridCells.Add((NewCell));
		}
	}

	this->SetActorLocation(FVector((-Width * CellSize - CellSize) / 2, (-Height * CellSize - CellSize) / 2, 0));
}

FVector ACGrid::GetWorldPositionFromGridPosition(int32 X, int32 Y) const
{
	return GetActorLocation() + FVector(X * CellSize + CellSize, Y * CellSize + CellSize, 0.0f);
}

ACCellActor* ACGrid::GetCellFromWorldPosition(FVector WorldPosition) const
{
	for (ACCellActor* cell : GridCells)
	{
		if (cell->GetActorLocation() == WorldPosition)
			return cell;
	}

	return nullptr;
}

void ACGrid::GetGridPositionFromWorldPosition(const FVector& WorldPosition, int32& OutX, int32& OutY) const
{
	for (auto Cell : GridCells)
	{
		if (Cell->GetActorLocation() == WorldPosition)
		{
			OutX = Cell->X;
			OutY = Cell->Y;
			return;
		}
	}
}

bool ACGrid::IsValidGridPosition(int32 X, int32 Y) const
{
	return X >= 0 && X < Width && Y >= 0 && Y < Height;
}

ACCellActor* ACGrid::GetCell(int32 X, int32 Y) const
{
	for (ACCellActor* CellActor : GridCells)
	{
		if (CellActor->X == X && CellActor->Y == Y)
			return CellActor;
	}
	
	return nullptr;
}


