#include "FCCardInfo.h"

FCCardInfo::FCCardInfo()
{
	CardName = "";
	BackgroundColor = FLinearColor::Black;
	Links =  TArray<ELinkDirection>{ };
}

FCCardInfo::FCCardInfo(FString InCardName, FLinearColor InBackgroundColor, TArray<ELinkDirection> InLinks)
{
	CardName = InCardName;
	BackgroundColor = InBackgroundColor;
	Links = InLinks;
}
