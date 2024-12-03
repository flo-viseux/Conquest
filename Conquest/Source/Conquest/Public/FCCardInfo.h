#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FCCardInfo.generated.h"

UENUM(BlueprintType)
enum class ECLinkDirection : uint8
{
	Top,
	Bottom,
	Left,
	Right
};

UENUM(BlueprintType)
enum class ECCardType : uint8
{
	Path,
	Castle,
	Objective
};


USTRUCT(BlueprintType)
struct FCCardInfo
{
	GENERATED_BODY()
public:
	FCCardInfo();

	FCCardInfo(FString InCardName, ECCardType InCardType, int InIndex, UTexture2D* InTexture1, UTexture2D* InTexture2, TArray<ECLinkDirection> InLinks);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECCardType CardType;

	// PlayerIndex
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Index;

	// Texture if player 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture1;

	// Texture if player 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ECLinkDirection> Links;
};
