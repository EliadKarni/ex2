#pragma once
#include <string.h>
#include <vector>
#include "player.h"
#include "player_state.h"
#include "Map.h"

using std::vector;
using std::string;

class Controller {
public:
	Controller(const string &filename = "");
	~Controller();
	
	void runGame(PlayerState &state);
	void printScreen();
	void playerDied();
	bool playEnemyesTurn();
private:
	Map m_map;
	vector<Location> m_coinsList;
	vector<Location> m_enemyList;
	Player m_player;
};
