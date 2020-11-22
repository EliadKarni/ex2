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
void Controller::runGame(fstream &boardsReader, PlayerState& state) {
	int nextlevelIndex = this->loadLevel(boardsReader, 0), 
		levelIndex = 0, 
		level = 1;
	while (state.getLifeState() != 0){
		//TODO print!!!
		this->playPlayerTurn();
		this->playEnemyesTurn();
		for (int i = 0; i < this->m_enemyList.size(); ++i)
			if (this->m_enemyList[i].getLocation() ==
				this->m_player.getLocation()) {
				state.die();
				this->loadLevel(boardsReader, levelIndex);
			}
		for (int i = 0; i < this->m_coinsList.size(); ++i)
			if (this->m_coinsList[i] == this->m_player.getLocation()) {
				this->m_coinsList.erase(this->m_coinsList.begin() + i);
				state.collectCoin(level);
			}
		if (this->m_coinsList.size() == 0) {
			levelIndex = nextlevelIndex;
			nextlevelIndex = this->loadLevel(boardsReader, levelIndex);
		}
	}
}
/*----------------------------------------------------------------------------
 * The method is loading the level next to the location in the board file.
 * update the controller values by the received level info.
 * input: fstream to the levels info file, levels location in the file.
 * output: the next level's location in the file.
*/
int Controller::loadLevel(fstream& boardsReader, int index) {
	//------------------------ parameters declaretion ---------------------------
	string input;
	bool playerReceived = false;
	int size = 0;
	vector<vector<int>> tempMap;

	//------------------------------------ receiving level's size ---------------------------------------
	size = receiveLevelSize(boardsReader);
	boardsReader >> input;
	for (int i = 0; i < input.length(); ++i) {
		if (isdigit(input[i])) {
			size *= 10;
			size += input[i] - '0';
		}
		else{
			std::cerr << "loading level error!\n";
			exit (EXIT_FAILURE);
		}
	}
	tempMap.resize(size);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			char input = boardsReader.get();
			//check the value of the next char at the file.
			switch (input){
			case ' ':
				tempMap[i].push_back(input);
				break;
			case WALL:
				tempMap[i].push_back(input);
				break;
			case LADDER:
				tempMap[i].push_back(input);
				break;
			case ROD:
				tempMap[i].push_back(input);
				break;
			case PLAYER_STAND_MODE:
				tempMap[i].push_back(' ');
				if (playerReceived) {
					std::cerr << "level syntax error!\n";
					exit (EXIT_FAILURE);
				}
				playerReceived = true;
				this->m_player = Location(j, i);
				break;
			case PLAYER_CLIMB_MODE:
				tempMap[i].push_back(' ');
				if (playerReceived) {
					std::cerr << "level syntax error!\n";
					exit(EXIT_FAILURE);
				}
				playerReceived = true;
				this->m_player = Location(j, i);
				break;
			case ENEMY_SYMB:
				tempMap[i].push_back(' ');
				this->m_enemyList.push_back(Enemy(Location(j, i)));
				break;
			case '*':
				tempMap[i].push_back(' ');
				this->m_coinsList.push_back(Location(j, i));
				break;
			default:
				if (playerReceived) {
					std::cerr << "level syntax error!\n";
					exit(EXIT_FAILURE);
				}
				break;
			}
			boardsReader.put('\n');
		}
	}
	return(boardsReader.tellg());
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::playEnemyesTurn() {
	for(int i = 0; i < this->m_enemyList.size(); ++i)
		this->m_enemyList[i].setLocation
		(this->m_map.calcEnemyMove(this->m_enemyList[i].getLocation(),
			this->m_player.getLocation()));
}
/*----------------------------------------------------------------------------
 * The method
 * input: .
 * output:
*/
void Controller::playPlayerTurn() {
	Location newLocation = this->m_player.getLocation();
	while (this->m_player.getLocation() == newLocation) {
		newLocation =
			m_map.isMovePossible(
				this->m_player.getLocation(), Keyboard::getch()
			);
	}
}