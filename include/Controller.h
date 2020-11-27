#pragma once

#define BOARD_PATH "\levels\level.txt"
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
	//------------------------- constractors section -------------------------

	Controller();
	//------------------------- method section -------------------------------

	void runGame();
	void printScore();
	void levelUp();
	bool playEnemyesTurn();
	void checkForCoinsCollect();
	void playerDead();
	void printStage()const;
	void addMapParameters(vector<vector<char>>& stage)const;
private:
	Map m_map;
	vector<Location> m_coinsList;
	vector<Enemy> m_enemyList;
	Player m_player;
	PlayerState m_state;
	ifstream boardReader;
};
