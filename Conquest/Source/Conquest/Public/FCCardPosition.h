#pragma once

#include "CoreMinimal.h"
#include "CCardActor.h"
#include "Engine/DataTable.h"
#include "FCCardPosition.generated.h"

USTRUCT(BlueprintType)
struct FCCardPosition
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCCardInfo CardInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CardPosition;
};
