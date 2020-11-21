#pragma once
#include "Map.h"
#include "Location.h"
#include "io.h"
#include <ostream>
#include <string>
using std::ifstream;
using std::cerr;
using std::nothrow;

Map::Map(ifstream fileReader)
{
	fileReader >> this->MapSize; //read the size of the map
	fileReader >> getc();        //break line
	CreateStageMap(fileReader);
}

Map::~Map() {
	int row;
	for (row = 0; row < MapSize; row++)
		delete[] StageMap[row];

	delete StageMap;
}

bool Map::isCoinExist(const Location& point)
{
	if (this->StageMap[point.col][point.row] == '*')
	{
		this->NumOfCoins--;
		return true;
	}
	return false;
}

char** Map::getStageMap() const { return StageMap; }
int    Map::getMapSize()  const { return MapSize;  }

/*
* This function get a file reader from the Game Controller,
* and load a new stage from the Board.txt file.
*/
void Map::CreateStageMap(ifstream fileReader)
{
	int col, row;
	//allocate memory:
	StageMap = new(nothrow) char* [MapSize];
	for (row = 0; row < MapSize; row++) {
		StageMap[row] = new(nothrow) char[MapSize];
	}
	//read the map from Board.txt:
	for (row = 0; row < MapSize; row++)
		for (col = 0; col < MapSize; col++)
		{
			fileReader >> StageMap[row][col];
			if (StageMap[row][col] == '*')
				this->NumOfCoins++;
		}
}

/*
* Input: Location of some object and keyboard value(UP/DOWN/LEFT/RIGHT)
* Output: True - possible movement
*         False - unpossible movement
*/
bool Map::isMovePossible(const Location& Objloc, int WantedMove )
{
	switch (WantedMove) {
	case KB_UP: 
		if (StageMap[Objloc.row - 1][Objloc.col] == WALL || 
			StageMap[Objloc.row - 1][Objloc.col] == ' ')
			return false;

	case KB_DOWN:
		if (StageMap[Objloc.row + 1][Objloc.col] == FLOOR)
			return false;

	case KB_LEFT:
		if (StageMap[Objloc.row][Objloc.col - 1] == WALL)
			return false;
		if (StageMap[Objloc.row][Objloc.col] == 'S' &&
			StageMap[Objloc.row][Objloc.col - 1] == ' ')) //player on ladder
			return false;

	case KB_RIGHT:
		if (StageMap[Objloc.row][Objloc.col + 1] == WALL)
			return false;
		if (StageMap[Objloc.row][Objloc.col] == 'S' &&
			StageMap[Objloc.row][Objloc.col+1] == ' ')   //player on ladder
			return false;
	}
	return true;
}

