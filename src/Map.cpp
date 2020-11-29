#include "Map.h"
#include "Location.h"
#include "io.h"
#include <ostream>
#include <vector>
using std::ifstream;

//========================================================================
Map::Map(vector<vector<char>> stage, Location initialPlayerLoc,
	vector<Location> initialCoinsLoc, vector<Location> initialEnemiesLoc) :
	m_stageMap(stage), m_mapSize((int)stage.size()),
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
Location Map::upMove(const Location& ObjLoc) const{
	if (mapException(Location(ObjLoc.row - 1, ObjLoc.col)) && 
		getContent(Location(ObjLoc.row, ObjLoc.col)) == LADDER)
			return Location(ObjLoc.row - 1, ObjLoc.col);

	return ObjLoc; //player can move up only on the ladder
}
//========================================================================
Location Map::downMove(const Location& objLoc) const{
	if (!mapException(Location(objLoc.row + 1, objLoc.col)))
		return objLoc;

	if (getContent(Location(objLoc.row + 1, objLoc.col)) == NOTHING)
		return getLocationAfterFallDown(Location(objLoc.row + 1, objLoc.col));
	if (getContent(Location(objLoc.row + 1, objLoc.col)) == LADDER)
		return Location(objLoc.row + 1, objLoc.col);

	return objLoc;
}
//========================================================================
Location Map::rightMove(const Location& objLoc) const{
	if (!mapException(Location(objLoc.row, objLoc.col + 1))) //player can't move to the wall
		return objLoc;
	if (getContent(Location(objLoc.row, objLoc.col + 1)) == ROD||
		getContent(Location(objLoc.row, objLoc.col + 1)) == LADDER ||
		!mapException(Location(objLoc.row + 1, objLoc.col + 1)))
		return(Location(objLoc.row, objLoc.col + 1));

	else if(getContent(Location(objLoc.row + 1, objLoc.col + 1)) != WALL &&
		getContent(Location(objLoc.row + 1, objLoc.col + 1)) != LADDER)
		return getLocationAfterFallDown(Location(objLoc.row + 1, objLoc.col + 1));

	return Location(objLoc.row, objLoc.col + 1); //can move right
}
//========================================================================
Location Map::leftMove(const Location& objLoc) const{
	if (!mapException(Location(objLoc.row, objLoc.col - 1))) //player can't move to the wall
		return objLoc;
	if (getContent(Location(objLoc.row, objLoc.col - 1)) == ROD ||
		getContent(Location(objLoc.row, objLoc.col - 1)) == LADDER ||
		!mapException(Location(objLoc.row + 1, objLoc.col - 1)))
		return(Location(objLoc.row, objLoc.col - 1));

	else if (getContent(Location(objLoc.row + 1, objLoc.col - 1)) != WALL &&
		getContent(Location(objLoc.row + 1, objLoc.col - 1)) != LADDER)
		return getLocationAfterFallDown(Location(objLoc.row + 1, objLoc.col - 1));

	return Location(objLoc.row, objLoc.col - 1); //can move left
}
//========================================================================
Location Map::getLocationAfterFallDown(const Location& objloc) const{
	int row = objloc.row;
	while (mapException(Location(row, objloc.col))) {
		if (getContent(Location(row, objloc.col)) == ROD)
			break;
		if (!mapException(Location(1 + row, objloc.col))||
			getContent(Location(1 + row, objloc.col)) == LADDER ||
			getContent(Location(1 + row, objloc.col)) == WALL) {
			break;
		}
		row++;
	}
	return Location(row,objloc.col);
}
//========================================================================
char Map::getContent(const Location& loc) const
{
	return m_stageMap[loc.row][loc.col];
}
//========================================================================
bool Map::mapException(const Location& loc) const{
	if (!inRectangle(Location(0, 0), Location(this->m_mapSize, this->m_mapSize), loc))
		return false;
	if(m_stageMap[loc.row][loc.col] == WALL)
		return false;

	return true;
}
