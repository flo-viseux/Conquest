#include "FCCell.h"

FCCell::FCCell()
{
	CellPosition = FVector(0);
	X = 0;
	Y = 0;
	bIsOccuped = false;
	CardInfo = FCCardInfo();
}

FCCell::FCCell(FVector InCellPosition, int32 InX, int32 InY, bool InIsOccuped, FCCardInfo InCardInfo)
{
	CellPosition = InCellPosition;
	X = InX;
	Y = InY;
	bIsOccuped = InIsOccuped;
	CardInfo = InCardInfo;
}
