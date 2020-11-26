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
	int MapSize;
	Location InitialPlayerLocation;
	vector<Location> InitalsEnemyLocationsList;
	ifstream FileReader;
	
public:
	Map();
	
	vector<vector<char>> getStageMap()               const;
	int getMapSize()                                 const;
	Location GetInitialPlayerLocation()              const;
	vector<Location> GetInitalsEnemyLocationsList()  const;
	
	void LoadNewStage();
	Location isMovePossible         (const Location&, int);
	Location GetLocationAfterFallDown    (const Location&);
	Location UpMove                      (const Location&);
	Location DownMove                    (const Location&);
	Location RightMove                   (const Location&);
	Location LeftMove                    (const Location&);
	Location FoolEnemy                   (const Location&);
	Location SmartEnemy(const Location&, const Location& );
	bool isLevelsOver();
	char GetContent(const Location&) const;
};
