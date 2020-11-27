#pragma once
//---------------------------- include section -------------------------------
#include <string.h>
#include <fstream>
#include <vector>
#include "player.h"
#include "Enemy.h"
#include "player_state.h"
#include "Map.h"

//------------------------------ using section -------------------------------
using std::vector;
using std::string;
using std::fstream;

/*----------------------------------------------------------------------------
 * Controller
 * The class is managing an a game by the demanded rols and active each of
 * the game's object by the needed order.
*/
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
