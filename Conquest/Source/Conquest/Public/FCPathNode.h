#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FCPathNode.generated.h"

struct FCPathNode
{
	FVector Position;
	TArray<FVector> Path;

	FCPathNode()
		: Position(FVector::ZeroVector)
	{}

	FCPathNode(const FVector& InPosition, const TArray<FVector>& InPath)
		: Position(InPosition), Path(InPath)
	{}
};
