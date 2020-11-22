#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include"Location.h"
#include "io.h"
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
	vector<Location> InitalsEnemyLocationsList;
	
public:
	Map(ifstream&);
	bool isCoinExist(const Location& point);
	
	vector<vector<char>> getStageMap()const;
	int getMapSize() const;
	Location GetInitialPlayerLocation() const;
	vector<Location> GetInitalsEnemyLocationsList() const;
	
	void CreateStageMap(ifstream&);
	Location isMovePossible(const Location&, int);
	Location GetLocationAfterFallDown(Location);
	Location UpMove(Location);
	Location DownMove(Location);
	Location RightMove(Location);
	Location LeftMove(Location);
	Location EnemyMove(Location);
};
