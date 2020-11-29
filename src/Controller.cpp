/* Controller
 * ===========================================================================
 */
//---------------------------- include section -------------------------------
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Controller.h"
#include "Enemy.h"
#include "BoardReader.h"
#include "Map.h"
#include "io.h"

//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is building  the object using array of 3 received Vertexes.
 * input: The constractor is the default constractor.
 * output: none.
*/
Controller::Controller() :m_boardReader(BoardReader()), m_coinsList({}),
	m_enemyList({}), m_map(Map()), m_player(Player(Location())),
	m_state(PlayerState()) 
{}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method is loading the level, then running the levels till the game
 * ends.
 * input: levels info file reader, the game state.
 * output: none.
*/
void Controller::runGame() {
	this->levelUp();
	while (this->m_state.getLifeState() != 0){
		if (this->m_coinsList.size() == 0) {
			if (this->m_boardReader.thereIsNextLevel())
				this->levelUp();
			else
				break;
		}
		this->printStage();
		//-------------------------- play turns ------------------------------
		this->m_player.PlayTurn(this->m_map);
		if (this->playEnemyesTurn()) {
			this->playerDead();
		}
		//--------------------- check for coins collection -------------------
		else
			this->checkForCoinsCollect();
	}
	system("cls");
	printScore();
}
/*----------------------------------------------------------------------------
 * The method print the game score.
 * input: none.
 * output: none.
*/
void Controller::printScore() {
	if (this->m_state.getLifeState() == 0)
		std::cout << "you lost the game!\n";
	else
		std::cout << "you won the game!\n";
	std::cout << "your score is: " << this->m_state.getScoreState();
}
/*----------------------------------------------------------------------------
 * The method is playing each enemy of the map turn and return if one of
 * the enemys have cached the player.
 * input: none.
 * output: if one of the enemy where able to cach the player.
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
 * The method is cheking if the player picked one of the game coins
 * if he is, the method update the needed data.
 * input: none.
 * output: none.
*/
void Controller::checkForCoinsCollect() {
	for (int i = 0; i < this->m_coinsList.size(); ++i)
		if (this->m_coinsList[i] == this->m_player.getLocation()) {
			this->m_coinsList.erase(this->m_coinsList.begin() + i);
			m_state.collectCoin();
		}
}
/*----------------------------------------------------------------------------
 * The method update the needed data in the player deth occation
 * input: none.
 * output: none.
*/
void Controller::playerDead() {
	this->m_state.die();
	if (this->m_state.getLifeState() > 0) {
		this->m_coinsList = this->m_map.getInitalsCoinsLocs();
		this->m_enemyList = {};
		for(int i = 0; i < this->m_map.getInitalsEnemyLocs().size()
			; ++i)
			this->m_enemyList.push_back(
				Enemy(this->m_map.getInitalsEnemyLocs()[i]));
		this->m_player = this->m_map.getInitialPlayerLoc();
	}
}
/*----------------------------------------------------------------------------
 * The method is update the needed data in an level up occation.
 * input: none.
 * output: none.
*/
void Controller::levelUp() {
	this->m_map = this->m_boardReader.readNextLevel();
	this->m_enemyList = {};
	this->m_coinsList = {};

	this->m_state.levelup();
	this->m_coinsList = this->m_map.getInitalsCoinsLocs();

	for(int i = 0; i < this->m_map.getInitalsEnemyLocs().size(); ++i){
		this->m_enemyList.push_back
		(Enemy(this->m_map.getInitalsEnemyLocs()[i]));
	}
	this->m_player = Player(this->m_map.getInitialPlayerLoc());
}
/*----------------------------------------------------------------------------
 * The method is printing the current stage.
 * input: none.
 * output: none.
*/
void Controller::printStage() const {
	vector<vector<char>> stage = this->m_map.getStageMap();
	addMapParameters(stage);
	system("cls");
	for (int row = 0; row < this->m_map.getMapSize(); ++row) {
		for (int col = 0; col < this->m_map.getMapSize(); ++col) 
			std::cout << stage[row][col];
		std::cout << std::endl;
	}
	std::cout << "level: " << this->m_state.getLevelState()
		<< " life: " << this->m_state.getLifeState()
		<< " score: " << this->m_state.getScoreState() << std::endl;
}
/*----------------------------------------------------------------------------
 * The method is adding the received map the dynamic parameters.
 * input: stage's vector.
 * output: none.
*/
void Controller::addMapParameters(vector<vector<char>> & stage) const{
	if (stage[this->m_player.getLocation().row]
		[this->m_player.getLocation().col] == LADDER)
		stage[this->m_player.getLocation().row]
		[this->m_player.getLocation().col] = PLAYER_CLIME;
	else
		stage[this->m_player.getLocation().row]
		[this->m_player.getLocation().col] = PLAYER;
	for (int i = 0; i < this->m_coinsList.size(); ++i)
		stage[this->m_coinsList[i].row]
		[this->m_coinsList[i].col] = '*';
	for (int i = 0; i < this->m_enemyList.size(); ++i)
		stage[this->m_enemyList[i].getLocation().row]
		[this->m_enemyList[i].getLocation().col] = ENEMY;
}