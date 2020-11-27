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
	Map(vector<vector<char>> stage = {},
		Location m_initialPlayerLoc = Location(),
		vector<Location> m_initialCoinsLoc = {},
		vector<Location> m_initialEnemiesLoc = {});

	Location GetInitialPlayerLocation()					const;
	vector<Location> GetInitalsEnemyLocationsList()		const;
	vector<vector<char>> getStageMap()					const;
	int getMapSize()									const;
	
	Location isMovePossible         (const Location&, int)const;
	Location GetLocationAfterFallDown    (const Location&)const;
	Location UpMove                      (const Location&)const;
	Location DownMove                    (const Location&)const;
	Location RightMove                   (const Location&)const;
	Location LeftMove                    (const Location&)const;
	Location FoolEnemy                   (const Location&)const;
	Location SmartEnemy(const Location&, const Location& )const;
	char GetContent(const Location&) const;
	bool MapException(const Location&);
};
