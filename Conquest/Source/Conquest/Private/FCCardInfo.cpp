#include "FCCardInfo.h"

FCCardInfo::FCCardInfo()
{
	CardName = "";
	CardType = ECCardType::Path;
	PlayerIndex = 0;
	Texture1 = nullptr;
	Texture2 = nullptr;
	Texture1UI = nullptr;
	Texture2UI = nullptr;
	Links =  TArray<ECLinkDirection>{ };
}

FCCardInfo::FCCardInfo(FString InCardName, ECCardType InCardType, int InIndex, UTexture2D* InTexture1, UTexture2D* InTexture2, UTexture2D* InTexture1UI, UTexture2D* InTexture2UI, TArray<ECLinkDirection> InLinks)
{
	CardName = InCardName;
	CardType = InCardType;
	PlayerIndex = InIndex;
	Texture1 = InTexture1;
	Texture2 = InTexture2;
	Texture1UI = InTexture1UI;
	Texture2UI = InTexture2UI;
	Links = InLinks;
}
