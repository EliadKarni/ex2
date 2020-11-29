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
#define LADDER 'H'
#define ROD  '-'
#define PLAYER_CLIME 'S'
#define COIN '*'
#define PLAYER '@'
#define ENEMY '%'
//===============================================
class Map {
private:
	vector<vector<char>> m_stageMap;
	int m_mapSize;
	Location m_initialPlayerLoc;
	vector<Location> m_initialCoinsLoc;
	vector<Location> m_initialEnemiesLoc;
	
public:
	Map(vector<vector<char>> m_stage = {},
		Location m_initialPlayerLoc = Location(),
		vector<Location> m_initialCoinsLoc = {},
		vector<Location> m_initialEnemiesLoc = {});

	Location getInitialPlayerLoc()						const;
	vector<Location> getInitalsEnemyLocs()				const;
	vector<Location> getInitalsCoinsLocs()				const;
	vector<vector<char>> getStageMap()					const;
	int getMapSize()									const;
	
	Location isMovePossible         (const Location&, int)const;
	Location getLocationAfterFallDown    (const Location&)const;
	Location upMove                      (const Location&)const;
	Location downMove                    (const Location&)const;
	Location rightMove                   (const Location&)const;
	Location leftMove                    (const Location&)const;
	Location calcEnemyMove  (const Location&, const Location&)const;
	char getContent(const Location&)					  const;
	bool mapException(const Location&) const;
};
