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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CellPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOccuped;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCCardInfo CardInfo;
	
};
