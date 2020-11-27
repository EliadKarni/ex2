#pragma once
#include "Map.h"
#include "Location.h"
#include "io.h"
#include <ostream>
#include <vector>
#include <time.h>
using std::ifstream;

//========================================================================
Map::Map()
{
	fileReader.open("Board.txt");
	if (!fileReader.is_open()) {
		std::cerr << "Game loading failed !  Make sure all files exist !";
		exit (EXIT_FAILURE);
	}
	fileReader >> this->mapSize; //read the size of the map
	fileReader.get();        //break line
	LoadNewStage();
}
//========================================================================
vector<vector<char>> Map::getStageMap()              const { return stageMap; }
int    Map::getMapSize()                             const { return mapSize;  }
Location Map::GetInitialPlayerLocation()             const { return initialPlayerLocation; }
vector<Location> Map::GetInitalsEnemyLocationsList() const { return initalsEnemyLocationsList; }
//========================================================================
/*
* This function get a file reader from the Game Controller,
* and load a new stage from the Board.txt file.
*/
void Map::LoadNewStage()
{
	char c;
	int row;
	bool player_exist=false;
	fileReader >> this->mapSize; //read the size of the map
	fileReader >> c;        //break line
	for (row = 0; row < mapSize; row++)
	{
		fileReader >> c;
		if(c!=PLAYER && c!=ENEMY && c!=ON_LADDER)
		stageMap[row].push_back(c);
		//save initial locations of diff objs:
		else {
			stageMap[row].push_back(' ');
			switch (c) {
			case PLAYER: {
				if (!player_exist) {
					this->initialPlayerLocation = Location(row, stageMap[row].size() - 1);
					player_exist = true;
					break;
				}
				else {
					std::cout << "make sure there is one player on the map!";
					EXIT_FAILURE;
				}
			}
			case ENEMY: {
				Location EnemyLocation(row, stageMap[row].size() - 1);
				initalsEnemyLocationsList.push_back(EnemyLocation);
				break;
			}
			case ON_LADDER: {
				if (!player_exist) {
					initialPlayerLocation = Location(row, stageMap[row].size() - 1);
					player_exist = true;
					break;
				}
				else {
					std::cout << "make sure there is one player on the map!";
					EXIT_FAILURE;
				}
			}
			}
		}
		fileReader >> c; //break line
	}
	fileReader >> c; //ready to read the next stage
}
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
	if (stageMap[Objloc.row][Objloc.col] == ON_LADDER)
		return Location(Objloc.row - 1, Objloc.col);

		return Objloc; //player can move up only on the ladder
}
//========================================================================
Location Map::DownMove(const Location& Objloc) const{
	if (stageMap[Objloc.row + 1][Objloc.col] == WALL) //player can't move to the wall
		return Objloc; 

	if (stageMap[Objloc.row + 1][Objloc.col] == LADDER)
		return Location(Objloc.row+1,Objloc.col);     //player move down on ladder

	return GetLocationAfterFallDown(Objloc); //player can fall down from rod/ladder/floor
}
//========================================================================
Location Map::RightMove(const Location& Objloc) const{
	if (stageMap[Objloc.row][Objloc.col + 1] == WALL)
		return Objloc;

	if (stageMap[Objloc.row][Objloc.col] == ON_LADDER &&
		stageMap[Objloc.row+1][Objloc.col + 1] == NOTHING) //player on ladder
		return Objloc;

	return Location(Objloc.row, Objloc.col + 1); //can move right
}
//========================================================================
Location Map::LeftMove(const Location& Objloc) const{
	if (stageMap[Objloc.row][Objloc.col - 1] == WALL) //player can't move to the wall
		return Objloc;

	if (stageMap[Objloc.row][Objloc.col] == 'S' &&
		stageMap[Objloc.row-1][Objloc.col - 1] == NOTHING)   //player on ladder
		return Objloc;

	return Location(Objloc.row, Objloc.col - 1); //can move left
}
//========================================================================
Location Map::GetLocationAfterFallDown(const Location& objloc) const{
	int row=objloc.row+1;
	while (stageMap[row][objloc.col] == NOTHING) {
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
	return stageMap[loc.row][loc.col];
}
//========================================================================
bool Map::MapException(const Location& loc) {
	if (stageMap[loc.row][loc.col] == WALL || loc.row == 0 || loc.col == 0)
		return true;

	return false;
}
