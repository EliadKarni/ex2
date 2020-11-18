#pragma once
#include <fstream>
#include <iostream>
#include"Location.h"
#include "Coin.h"
#include "Ladder.h"
#include "Rod.h"

class Map {
private:
	char** StageMap;
	int MapSize, NumOfCoins;

public:
	Map();
	bool isCoinExist(const Location& point);
	void CoinCollected();
	char** getStageMap();
	int getMapSize();
};