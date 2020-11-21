#pragma once
#include <string.h>
#include "LinkedList.h"
#include "player.h"
#include "player_state.h"
#include "Map.h"

class Controller {
public:
	Controller();
	~Controller();
	
	void runGame(PlayerState &state);
	void printScreen();
	void playerDied();
	bool playEnemyesTurn();
private:
	Map m_map;
	LinkedList m_coinsList;
	LinkedList m_enemyList;
	Player m_player;
};
