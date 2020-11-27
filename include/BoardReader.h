#pragma once
//------------------------------ defines section -----------------------------
#define BOARD_PATH "\levels\level.txt"
//---------------------------- include section -------------------------------
#include <fstream>
#include <vector>
#include "Controller.h"
#include <Location.h>

/*----------------------------------------------------------------------------
 * BoardReader
 * The class is loading the Boards file, and return it's information by the
 * needed syntax.
*/
class BoardReader {
public:
	BoardReader();

	vector<Location> getPrimeCoins()const { return this->m_primeCoinsLoc; };
	vector<Location> getPrimeEnemy()const { return this->m_primeEnemiesLoc; };
	Location getPrimePlayer()const { return this->m_primePlayerLoc; };

	bool thereIsNextLevel(); // not const because tellg() isn't const.
	vector<vector<char>> readNextLevel();
private:
	int receiveMapSize();
	void resetArgs();

	ifstream m_boardReader;
	int m_fileTextSize;
	Location m_primePlayerLoc;
	vector<Location> m_primeCoinsLoc;
	vector<Location> m_primeEnemiesLoc;
};
