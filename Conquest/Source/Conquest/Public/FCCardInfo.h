#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FCCardInfo.generated.h"

USTRUCT(BlueprintType)
struct FCCardInfo : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor BackgroundColor;
};
