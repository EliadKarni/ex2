#pragma once
//------------------------------ defines section -----------------------------
#define BOARD_PATH "Board.txt"
//---------------------------- include section -------------------------------
#include <fstream>
#include <vector>
#include "Map.h"

/*----------------------------------------------------------------------------
 * BoardReader
 * The class is loading the Boards file, and return it's information by the
 * needed syntax.
*/
class BoardReader {
public:
	BoardReader();

	bool thereIsNextLevel(); // not const because tellg() isn't const.
	Map readNextLevel();
private:
	int receiveMapSize();

	ifstream m_boardReader;
	int m_fileTextSize;
};
