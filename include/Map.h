#pragma once
#include <fstream>
#include <iostream>
#include"Location.h"
#include "Coin.h"
#include "Ladder.h"
#include "Rod.h"

class Map {
private:
	char** StageMap; //i prefer int map so we'll could calc quiqest path for the enemyes
	int MapSize, NumOfCoins;  //Num of coins will be stored on the coins LinkedList

public:
	Map();
	bool isCoinExist(const Location& point); //controller supporsed to deal with it
	void CoinCollected(); //same^^
	char** getStageMap();
	int getMapSize();
};