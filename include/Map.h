#pragma once

#include <vector>
#include "Location.h"

#define WALL #
#define LADDER H
#define ROD  -

class Map {
private:
	vector<vector<int>> stageMap;
	int MapSize;
	
public:
	Map(vector<vector<int>> input = {}) : stageMap(input) {}
	~Map();
	bool isMovePossible(const Location& precentLoc, const Location& wantedLoc);
	//add find shortest path method
};
