#pragma once
#include <string.h>
#include <fstream>
#include <vector>
#include "player.h"
#include "Enemy.h"
#include "player_state.h"
#include "Map.h"

using std::vector;
using std::string;
using std::fstream;

class Controller {
public:
	Controller();
	
	void runGame();
	void finishGame();
	bool playEnemyesTurn();
	void checkForCoinsCollect(const int &level);
private:
	Map m_map;
	vector<Location> m_coinsList;
	vector<Enemy> m_enemyList;
	Player m_player;
	PlayerState m_state;
};
