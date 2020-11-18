#pragma once
#include "LinkedList.h"
#include "player.h"
#include "player_state.h"
#include "Map.h"


class Controller {
public:
	Controller();
	
	void runGame();
	void printScreen();
	void playerDied();
	void playEnemyesTurn();
private:
	Map m_map;
	LinkedList m_coinsList;
	LinkedList m_enemyList;
	Player m_player;
	PlayerState m_state;
};
