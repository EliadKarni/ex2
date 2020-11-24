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
	FileReader.open("Board.txt");
	if (!FileReader.is_open()) {
		std::cerr << "Game loading failed !  Make sure all files exist !";
		return EXIT_FAILURE;
	}
	
	LoadNewStage();
}
//========================================================================
vector<vector<char>> Map::getStageMap()              const { return StageMap; }
int    Map::getMapSize()                             const { return MapSize;  }
Location Map::GetInitialPlayerLocation()             const { return InitialPlayerLocation; }
vector<Location> Map::GetInitalsEnemyLocationsList() const { return InitalsEnemyLocationsList; }
//========================================================================
/*
* This function get a file reader from the Game Controller,
* and load a new stage from the Board.txt file.
*/
void Map::LoadNewStage()
{
	char c;
	int row;
	
	fileReader >> this->MapSize; //read the size of the new stage
	fileReader >> getc();        //break line
	
	for (row = 0; row < MapSize; row++)
	{
		fileReader >> c;
		StageMap[row].push_back(c);
		//save initial locations of diff objs:
		switch (c) {
		case PLAYER: {
			InitialPlayerLocation(row, StageMap[row].size() - 1);
		}
				
		case ENEMY: {
			Location EnemyLocation(row, StageMap[row].size() - 1);
			InitalsEnemyLocations.push_back(EnemyLocation);
			
		case ON_LADDER: {
			InitialPlayerLocation(row, StageMap[row].size() - 1);
		}
			
		}
		fileReader >> c; 
	    }
    }
	fileReader >> c; //ready to read the next map
}
//========================================================================
/*
* Input: Location of some object and keyboard value(UP/DOWN/LEFT/RIGHT)
* Output: Move is Possible-> New Location after the move.
*         Move isn't Possible-> The original Location.
*/
Location Map::isMovePossible(const Location& Objloc, int WantedMove )
{
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
Location Map::UpMove(const Location& Objloc) {
	if (StageMap[Objloc.row][Objloc.col] == ON_LADDER)
		return Location(Objloc.row - 1, Objloc.col);

		return Objloc; //player can move up only on the ladder
}
//========================================================================
Location Map::DownMove(const Location& Objloc) {
	if (StageMap[Objloc.row + 1][Objloc.col] == WALL) //player can't move to the wall
		return Objloc; 

	if (StageMap[Objloc.row + 1][Objloc.col] == LADDER)
		return Location(Objloc.row+1,Objloc.col);     //player move down on ladder

	return GetLocationAfterFallDown(Objloc); //player can fall down from rod/ladder/floor
}
//========================================================================
Location Map::RightMove(const Location& Objloc) {
	if (StageMap[Objloc.row][Objloc.col + 1] == WALL)
		return Objloc;

	if (StageMap[Objloc.row][Objloc.col] == ON_LADDER &&
		StageMap[Objloc.row+1][Objloc.col + 1] == NOTHING) //player on ladder
		return Objloc;

	return Location(Objloc.row, Objloc.col + 1); //can move right
}
//========================================================================
Location Map::LeftMove(const Location& Objloc) {
	if (StageMap[Objloc.row][Objloc.col - 1] == WALL) //player can't move to the wall
		return Objloc;

	if (StageMap[Objloc.row][Objloc.col] == 'S' &&
		StageMap[Objloc.row-1][Objloc.col - 1] == NOTHING)   //player on ladder
		return Objloc;

	return Location(Objloc.row, Objloc.col - 1); //can move left
}
//========================================================================
Location Map::GetLocationAfterFallDown(const Location& objloc) {
	int row=objloc.row+1;
	while (StageMap[row][objloc.col] == NOTHING) {
		row++;
	}
	return Location(row,objloc.col);
}
//========================================================================
Location Map::FoolEnemy(const Location& EnemyLoc) {
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
	return Location(EnemyLoc.row+1,EnemyLoc.col)
}
//========================================================================
/*
FUNCTION IN CONSRUCTION - NOT TO USE FOR NOW !!!
*/
Location Map::SmartEnemy(const Location& Enemy, const Location& Player) {

}
