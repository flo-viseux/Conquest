#include "FCCardInfo.h"

FCCardInfo::FCCardInfo()
{
	CardName = "";
	CardType = ECCardType::Path;
	Index = 0;
	Texture1 = nullptr;
	Texture2 = nullptr;
	Links =  TArray<ECLinkDirection>{ };
}

FCCardInfo::FCCardInfo(FString InCardName, ECCardType InCardType, int InIndex, UTexture2D* InTexture1, UTexture2D* InTexture2, TArray<ECLinkDirection> InLinks)
{
	CardName = InCardName;
	CardType = InCardType;
	Index = InIndex;
	Texture1 = InTexture1;
	Texture2 = InTexture2;
	Links = InLinks;
}
