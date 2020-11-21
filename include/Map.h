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
	Map();// i needed a default constractor
	Map(ifstream); //define it by unsigned int as its size, if 0 stage map = nullptr
	~Map();
	bool isCoinExist(const Location& point); //not needed
	char** getStageMap()const; //not needed
	int getMapSize() const; //not needed
	void CreateStageMap(ifstream); //not needed
	bool isMovePossible(const Location&, int);
	//add find shortest path method
};
