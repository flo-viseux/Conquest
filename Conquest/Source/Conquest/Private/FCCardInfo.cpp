#include "FCCardInfo.h"

FCCardInfo::FCCardInfo()
{
	CardName = "";
	Texture = nullptr;
	Links =  TArray<ELinkDirection>{ };
}

FCCardInfo::FCCardInfo(FString InCardName, UTexture2D* InTexture, TArray<ELinkDirection> InLinks)
{
	CardName = InCardName;
	Texture = InTexture;
	Links = InLinks;
}
