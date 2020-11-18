#pragma once
#include "Map.h"
#include "Location.h"
#include <fstream>

Map::Map()
{

}

bool Map::isCoinExist(const Location& point)
{
	if (this->StageMap[point.col][point.row] == '*')
	{
		CoinCollected();
		return true;
	}
	return false;
}
void Map::CoinCollected()
{
	this->NumOfCoins--;
}
char** Map::getStageMap() { return StageMap; }
int Map::getMapSize() { return MapSize; }
