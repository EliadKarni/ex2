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

	vector<vector<char>> readNextLevel();
private:
	ifstream m_boardReader;
	Location m_primePlayerLoc;
	vector<Location> m_primeCoinsLoc;
	vector<Location> m_primeEnemiesLoc;
};
