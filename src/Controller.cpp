/* Controller
 * ===========================================================================
 *
 */
 //---------------------------- include section -------------------------------
#include <iostream>
#include <string>
#include "Controller.h"
#include "Enemy.h"

using std::string;
//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is building  the object using array of 3 received Vertexes.
 * input: array of 3 Vertexes.
 * output: none.
*/
Controller::Controller(const string &filename) {
	this->m_map = Map();
	this->m_coinsList = LinkedList();
	this->m_enemyList = LinkedList();
	this->m_player = Player();
}

Controller::~Controller() {
	delete m_coinsList;
}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::runGame(PlayerState& state) {
	while (state.getLifeState() != 0 
		&& this->m_coinsList.m_size != 0){
		Node *coinsCounter = this->m_coinsList.m_root;

		this->printScreen();
		this->m_player.playerTurn();
		if ((*this).playEnemyesTurn()) {
			state.die();
		}
			
	}
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
bool Controller::playEnemyesTurn() {
	Node* enemyTurnCounter = this->m_enemyList.m_root;
	while (enemyTurnCounter != nullptr)
	{
		((Enemy*)(enemyTurnCounter->m_data))->
			playerTurn(this->m_player.getLocation());
		if (((Enemy*)(enemyTurnCounter->m_data))->getLocation() ==
			this->m_player.getLocation())
			return(true);
		else
			enemyTurnCounter = enemyTurnCounter->m_next;
	}
	return false;
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::printScreen() {

}