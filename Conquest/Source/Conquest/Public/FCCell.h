#pragma once


#include "CoreMinimal.h"
#include "FCCardInfo.h"
#include "Engine/DataTable.h"
#include "FCCell.generated.h"

USTRUCT(BlueprintType)
struct FCCell
{
	GENERATED_BODY()
	
public:
	FCCell();

	FCCell(FVector InCellPosition, int32 InX, int32 InY, bool InIsOccuped, FCCardInfo InCardInfo);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CellPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOccuped;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCCardInfo CardInfo;
	
};
