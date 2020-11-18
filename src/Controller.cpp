/* Controller
 * ===========================================================================
 *
 */
 //---------------------------- include section -------------------------------
#include "Controller.h"
#include "Enemy.h"
//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is building  the object using array of 3 received Vertexes.
 * input: array of 3 Vertexes.
 * output: none.
*/
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::runGame() {
	while (this->m_state.getLifeState() != 0 
		&& this->m_coinsList.m_size != 0){
		Node *coinsCounter = this->m_coinsList.m_root;

		this->printScreen();
		this->m_player.playerTurn();
		playEnemyesTurn();
		checkIfCoinCollected();
	}
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::playEnemyesTurn() {
	Node* enemyTurnCounter = this->m_enemyList.m_root;
	while (enemyTurnCounter != nullptr)
	{
		((Enemy*)(enemyTurnCounter->m_data))->
			playerTurn(this->m_player.getLocation());
		if (((Enemy*)(enemyTurnCounter->m_data))->getLocation() ==
			this->m_player.getLocation())
			this->playerDied();
		else
			enemyTurnCounter = enemyTurnCounter->m_next;
	}
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::printScreen() {

}