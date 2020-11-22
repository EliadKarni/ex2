/* Controller
 * ===========================================================================
 *
 */
 //---------------------------- include section -------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Controller.h"
#include "Enemy.h"
#include "io.h"

using std::fstream;
using std::vector;
//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is building  the object using array of 3 received Vertexes.
 * input: The constractor is the default constractor.
 * output: none.
*/
Controller::Controller() {
	this->m_map = Map();
	this->m_coinsList = {};
	this->m_enemyList = {};
	this->m_player = Player();
}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is loading the level, then running the levels till the game
 * ends.
 * input: levels info file reader, the game state.
 * output: none.
*/
void Controller::runGame() {
	int	level = 1;
	//TODO load map
	while (this->m_state.getLifeState() != 0){
		while (this->m_coinsList.size() == 0) {
			// TODO: check if game finished.
			++level;
			// TODO load next level
		}
		//TODO print stage!!!
		//-------------------------- play turns ------------------------------
		this->m_player.PlayTurn(this->m_map);
		if (this->playEnemyesTurn()) {
			m_state.die();
		}
		//--------------------- check for coins collection -------------------
		else
			this->checkForCoinsCollect(level);
	}
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::finishGame() {

}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
bool Controller::playEnemyesTurn() {
	for (int i = 0; i < this->m_enemyList.size(); ++i) {
		this->m_enemyList[i].playTurn(this->m_map,
			this->m_player.getLocation());
		if (this->m_enemyList[i].getLocation()
			== this->m_player.getLocation())
			return true;
	}
	return false;
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::checkForCoinsCollect(const int &level) {
	for (int i = 0; i < this->m_coinsList.size(); ++i)
		if (this->m_coinsList[i] == this->m_player.getLocation()) {
			this->m_coinsList.erase(this->m_coinsList.begin() + i);
			m_state.collectCoin(level);
		}
}