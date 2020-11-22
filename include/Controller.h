#pragma once
#include <string.h>
#include <fstream>
#include <vector>
#include "player.h"
#include "player_state.h"
#include "Map.h"

using std::vector;
using std::string;
using std::fstream;

class Controller {
public:
	Controller();
	
	void runGame(fstream &boardsReader, PlayerState &state);
	int loadLevel(fstream& boardsReader, int index);
	void playEnemyesTurn();
	void playPlayerTurn();
	int receiveLevelSize(fstream &boardsReader);
private:
	Map m_map;
	vector<Location> m_coinsList;
	vector<Enemy> m_enemyList;
	Player m_player;
};
