#pragma once
#include <fstream>
#include <iostream>
#include"Location.h"
#include "Coin.h"
#include "LinkedList.h"
#include <ostream>
#include "io.h"
#include <vector>
using std::ifstream;
using std::vector;
//===============================================
#define NOTHING ' '
#define WALL '#'
#define FLOOR '#'
#define LADDER 'H'
#define ROD  '-'
#define ON_LADDER 'S'

#define PLAYER '@'
#define ENEMY '%'
//===============================================
class Map {
private:
	vector<vector<char>> StageMap;
	int MapSize, NumOfCoins; 
	Location InitialPlayerLocation;
	vector<Location> InitalsEnemyLocations;
	
public:
	Map(ifstream&);
	bool isCoinExist(const Location& point);
	vector<vector<char>> getStageMap()const;
	int getMapSize() const;
	void CreateStageMap(ifstream&);
	Location isMovePossible(const Location&, int);
	Location GetLocationAfterFallDown(Location);
	Location UpMove(Location);
	Location DownMove(Location);
	Location RightMove(Location);
	Location LeftMove(Location);
};
