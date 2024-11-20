#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FCCardInfo.generated.h"

UENUM(BlueprintType)
enum class ELinkDirection : uint8
{
	Top,
	Bottom,
	Left,
	Right
};

USTRUCT(BlueprintType)
struct FCCardInfo
{
	GENERATED_BODY()
public:
	FCCardInfo();

	FCCardInfo(FString InCardName, FLinearColor InBackgroundColor, TArray<ELinkDirection> InLinks);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor BackgroundColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ELinkDirection> Links;
};
