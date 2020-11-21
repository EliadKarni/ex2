#pragma once

#include <vector>
#include "Location.h"

using std::vector;

#define WALL #
#define LADDER H
#define ROD  -

#define CLIME 'c'
#define WALK 'w'
#define FALL 'f'

class Map {
private:
	vector<vector<char>> *stageMap;
	int MapSize;
	
public:
	Map(vector<vector<char>> *input = nullptr) : stageMap(input) {}
	~Map();
	Location isMovePossible(const Location& precentLoc, int wantedMove);
	Location calcEnemyMove(const Location& precentLoc, const Location& playerLoc)//add find shortest path method
};