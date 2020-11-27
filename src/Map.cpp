#pragma once
#include "Map.h"
#include "Location.h"
#include "io.h"
#include <ostream>
#include <vector>
#include <time.h>
using std::ifstream;

//========================================================================
Map::Map(vector<vector<char>> stage = {},
	Location initialPlayerLoc = Location(),
	vector<Location> initialCoinsLoc = {},
	vector<Location> initialEnemiesLoc = {}) :
	m_stageMap(stage), m_mapSize(stage.size()),
	m_initialPlayerLoc(initialPlayerLoc), m_initialCoinsLoc(initialCoinsLoc),
	m_initialEnemiesLoc(initialEnemiesLoc) {}

//========================================================================
vector<vector<char>> Map::getStageMap()              const { return m_stageMap; }
int    Map::getMapSize()                             const { return m_mapSize;  }
Location Map::GetInitialPlayerLocation()             const { return m_initialPlayerLoc; }
vector<Location> Map::GetInitalsEnemyLocationsList() const { return this->m_initialEnemiesLoc; }
//========================================================================
/*
* Input: Location of some object and keyboard value(UP/DOWN/LEFT/RIGHT)
* Output: Move is Possible-> New Location after the move.
*         Move isn't Possible-> The original Location.
*/
Location Map::isMovePossible(const Location& Objloc, int WantedMove )
const{
	switch (WantedMove) {
	case KB_UP: 
		return UpMove(Objloc);
		
	case KB_DOWN:
		return DownMove(Objloc);

	case KB_LEFT:
		return LeftMove(Objloc);

	case KB_RIGHT:
		return RightMove(Objloc);
	}
}
//========================================================================
Location Map::UpMove(const Location& Objloc) const{
	if (m_stageMap[Objloc.row][Objloc.col] == PLAYER_CLIME)
		return Location(Objloc.row - 1, Objloc.col);

		return Objloc; //player can move up only on the ladder
}
//========================================================================
Location Map::DownMove(const Location& Objloc) const{
	if (MapException(Location(Objloc.row+1, Objloc.col))) //player can't move to the wall
		return Objloc; 

	if (StageMap[Objloc.row + 1][Objloc.col] == LADDER)
		return Location(Objloc.row+1,Objloc.col);     //player move down on ladder

	return GetLocationAfterFallDown(Objloc); //player can fall down from rod/ladder/floor
}
//========================================================================
Location Map::RightMove(const Location& Objloc) const{
	if (MapException(Location(Objloc.row, Objloc.col + 1))) //player can't move to the wall
		return Objloc;

	if (StageMap[Objloc.row][Objloc.col] == ON_LADDER &&
		StageMap[Objloc.row+1][Objloc.col + 1] == NOTHING) //player on ladder
		return Objloc;

	return Location(Objloc.row, Objloc.col + 1); //can move right
}
//========================================================================
Location Map::LeftMove(const Location& Objloc) const{
	if (MapException(Location(Objloc.row, Objloc.col - 1))) //player can't move to the wall
		return Objloc;

	if (StageMap[Objloc.row][Objloc.col] == 'S' &&
		StageMap[Objloc.row-1][Objloc.col - 1] == NOTHING)   //player on ladder
		return Objloc;

	return Location(Objloc.row, Objloc.col - 1); //can move left
}
//========================================================================
Location Map::GetLocationAfterFallDown(const Location& objloc) const{
	int row=objloc.row+1;
	while (m_stageMap[row][objloc.col] == NOTHING) {
		row++;
	}
	return Location(row,objloc.col);
}
//========================================================================
Location Map::FoolEnemy(const Location& EnemyLoc) const{
	srand(time(NULL));
	int randMove = (rand() % 4) + 1; 
	switch (randMove) {
	case 1: //move enemy up
		return Location(EnemyLoc.row - 1, EnemyLoc.col);
	case 2: //move enemy left
		return Location(EnemyLoc.row, EnemyLoc.col - 1);
	case 3: //move enemy right
		return Location(EnemyLoc.row, EnemyLoc.col + 1);
	}
	//move enemy down:
	return Location(EnemyLoc.row + 1, EnemyLoc.col);
}
//========================================================================
/*
FUNCTION IN CONSRUCTION - NOT TO USE FOR NOW !!!
*/
Location Map::SmartEnemy(const Location& Enemy, const Location& Player) {
}
//========================================================================
bool Map::isLevelsOver() {
	if (this->fileReader.eof())
		return true;

	return false;
}
//========================================================================
char Map::GetContent(const Location& loc) const
{
	return m_stageMap[loc.row][loc.col];
}
//========================================================================
bool Map::MapException(const Location& loc) {
	if (m_stageMap[loc.row][loc.col] == WALL || loc.row == 0 || loc.col == 0)
		return true;

	return false;
}
