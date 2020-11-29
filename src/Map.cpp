#include "Map.h"
#include "Location.h"
#include "io.h"
#include <ostream>
#include <vector>
using std::ifstream;

//========================================================================
Map::Map(vector<vector<char>> stage, Location initialPlayerLoc,
	vector<Location> initialCoinsLoc, vector<Location> initialEnemiesLoc) :
	m_stageMap(stage), m_mapSize(stage.size()),
	m_initialPlayerLoc(initialPlayerLoc), m_initialCoinsLoc(initialCoinsLoc),
	m_initialEnemiesLoc(initialEnemiesLoc) {}

//========================================================================
vector<vector<char>> Map::getStageMap()const 
{ return m_stageMap; }
int    Map::getMapSize()const 
{ return m_mapSize;  }
Location Map::getInitialPlayerLoc()const 
{ return this->m_initialPlayerLoc; }
vector<Location> Map::getInitalsCoinsLocs()const
{ return this->m_initialCoinsLoc; }
vector<Location> Map::getInitalsEnemyLocs() const 
{ return this->m_initialEnemiesLoc; }
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
		return upMove(Objloc);
		
	case KB_DOWN:
		return downMove(Objloc);

	case KB_LEFT:
		return leftMove(Objloc);

	case KB_RIGHT:
		return rightMove(Objloc);
	}
}
//========================================================================
Location Map::upMove(const Location& Objloc) const{
	if (m_stageMap[Objloc.row][Objloc.col] == LADDER)
		return Location(Objloc.row - 1, Objloc.col);

		return Location(Objloc.row - 1, Objloc.col); //player can move up only on the ladder
}
//========================================================================
Location Map::downMove(const Location& Objloc) const{
	if (mapException(Location(Objloc.row+1, Objloc.col))) //player can't move to the wall
		return Objloc; 

	if (this->m_stageMap[Objloc.row + 1][Objloc.col] == LADDER)
		return Location(Objloc.row+1,Objloc.col);     //player move down on ladder

	return getLocationAfterFallDown(Objloc); //player can fall down from rod/ladder/floor
}
//========================================================================
Location Map::rightMove(const Location& objLoc) const{
	if (mapException(Location(objLoc.row, objLoc.col + 1))) //player can't move to the wall
		return objLoc;

	if (this->m_stageMap[objLoc.row + 1][objLoc.col + 1] != WALL &&
		this->m_stageMap[objLoc.row + 1][objLoc.col + 1] != LADDER) //player on ladder
		return getLocationAfterFallDown(Location(objLoc.row, objLoc.col + 1));

	return Location(objLoc.row, objLoc.col + 1); //can move right
}
//========================================================================
Location Map::leftMove(const Location& objLoc) const{
	if (mapException(Location(objLoc.row, objLoc.col - 1))) //player can't move to the wall
		return objLoc;

	char ch = this->m_stageMap[objLoc.row + 1][objLoc.col - 1];
	if (this->m_stageMap[1 + objLoc.row][objLoc.col] != WALL &&
		this->m_stageMap[1 + objLoc.row][objLoc.col ] != LADDER) //player on ladder
		return getLocationAfterFallDown(Location(objLoc.row, objLoc.col - 1));

	return Location(objLoc.row, objLoc.col - 1); //can move left
}
//========================================================================
Location Map::getLocationAfterFallDown(const Location& objloc) const{
	int row = objloc.row;
	while (mapException(Location(row, objloc.col))) {
		if (m_stageMap[row][objloc.col] == ROD)
			break;
		if (m_stageMap[1 + row][objloc.col] == LADDER) {
			++row;
			break;
		}
		row++;
	}
	return Location(row,objloc.col);
}
//========================================================================
Location Map::calcEnemyMove(const Location& enemyLoc, 
	const Location& playerLoc) const{
	Location moveAns=enemyLoc;
	if (isRightOf(playerLoc, enemyLoc))
		moveAns = rightMove(enemyLoc);
	else if (isLeftOf(playerLoc, enemyLoc))
		moveAns = leftMove(enemyLoc);
	if (moveAns == enemyLoc) {
		if (isAboveOf(playerLoc, enemyLoc))
			moveAns = upMove(enemyLoc);
		else
			moveAns = downMove(enemyLoc);
	}
	
	return moveAns;
}
//========================================================================
char Map::getContent(const Location& loc) const
{
	return m_stageMap[loc.row][loc.col];
}
//========================================================================
bool Map::mapException(const Location& loc) const{
	if (m_stageMap[loc.row][loc.col] == WALL
		|| !inRectangle(Location(0 , 0), 
			Location(this->m_mapSize, this->m_mapSize), loc))
		return true;

	return false;
}
