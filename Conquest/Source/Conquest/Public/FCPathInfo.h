#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FCPathInfo.generated.h"

USTRUCT(BlueprintType)
struct FCPathInfo
{
	GENERATED_BODY()
public:
	TArray<FVector> PathCells;
	
	int StartNodeIndex;
	
	int Player0CardsCount;
	int Player1CardsCount;
};
