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
#define COIN '*'
#define PLAYER '@'
#define ENEMY '%'
//===============================================
class Map {
private:
	vector<vector<char>> stageMap;
	int mapSize;
	Location initialPlayerLocation;
	vector<Location> initalsEnemyLocationsList;
	ifstream fileReader;
	
public:
	Map();
	
	vector<vector<char>> getStageMap()               const;
	int getMapSize()                                 const;
	Location GetInitialPlayerLocation()              const;
	vector<Location> GetInitalsEnemyLocationsList()  const;
	
	void LoadNewStage();
	Location isMovePossible         (const Location&, int)const;
	Location GetLocationAfterFallDown    (const Location&)const;
	Location UpMove                      (const Location&)const;
	Location DownMove                    (const Location&)const;
	Location RightMove                   (const Location&)const;
	Location LeftMove                    (const Location&)const;
	Location FoolEnemy                   (const Location&)const;
	Location SmartEnemy(const Location&, const Location& )const;
	bool isLevelsOver();
	char GetContent(const Location&) const;
	bool MapException(const Location&);
};
