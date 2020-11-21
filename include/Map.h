#pragma once
#include <fstream>
#include <iostream>
#include"Location.h"
#include "Coin.h"
#include "LinkedList.h"
#include <ostream>
#include "io.h"
using std::ifstream;

#define WALL #
#define FLOOR #
#define LADDER H
#define ROD  -

class Map {
private:
	char** StageMap;
	int MapSize, NumOfCoins;
	
public:
	Map(ifstream);
	~Map();
	bool isCoinExist(const Location& point);
	char** getStageMap()const;
	int getMapSize() const;
	void CreateStageMap(ifstream);
	bool isMovePossible(const Location&, int);
};
