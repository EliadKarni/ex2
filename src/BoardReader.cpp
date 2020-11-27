/* BoardReader
 * ===========================================================================
 */
 //---------------------------- include section -------------------------------
#include "BoardReader.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "Utilities.cpp"
#include "Map.h"

//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is .
 * input: .
 * output: .
*/
BoardReader::BoardReader() {
	this->m_boardReader.open("asd");
	if (!(this->m_boardReader.is_open()))
		terminate("opening boards files error!");
	int primeLoc = (int)this->m_boardReader.tellg();
	this->m_boardReader.seekg(0, std::ios::end);
	this->m_fileTextSize = (int)this->m_boardReader.tellg();
	this->m_boardReader.seekg(primeLoc);
}
//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method .
 * input: .
 * output: .
*/
bool BoardReader::thereIsNextLevel() {
	return (this->m_boardReader.tellg() == (int)this->m_fileTextSize);
}
/*----------------------------------------------------------------------------
 * The method .
 * input: .
 * output: .
*/
vector<vector<char>> BoardReader::readNextLevel() {
	vector<vector<char>> map;
	bool playerReceived = false;
	string receivedline;
	char receivedChar;
	int size = receiveMapSize();

	resetArgs();
	for (int i = 0; i < size; ++i) {
		vector<char> receivedMapRow = {};
		for (int j = 0; j < size; ++j) {
			this->m_boardReader.get(receivedChar);
			switch (receivedChar)
			{
			case PLAYER:
				if (playerReceived)
					terminate("player received twice!");
				playerReceived = true;
				this->m_primePlayerLoc = Location(i,j);
				receivedMapRow.push_back(NOTHING);
				break;
			case PLAYER_CLIME:
				if (playerReceived)
					terminate("player received twice!");
				playerReceived = true;
				this->m_primePlayerLoc = Location(i, j);
				receivedMapRow.push_back(NOTHING);
				break;
			case ENEMY:
				this->m_primeEnemiesLoc.push_back(Location(i, j));
				receivedMapRow.push_back(NOTHING);
				break;
			case WALL:
				receivedMapRow.push_back(WALL);
				break;
			case NOTHING:
				receivedMapRow.push_back(NOTHING);
				break;
			case LADDER:
				receivedMapRow.push_back(LADDER);
				break;
			case ROD:
				receivedMapRow.push_back(ROD);
				break;
			case COIN:
				this->m_primeCoinsLoc.push_back(Location(i, j));
				receivedMapRow.push_back(NOTHING);
				break;
			default:
				string errorMessage = "receiving the char ";
					errorMessage.append(1, receivedChar);
					errorMessage.append(" not declered!");
				terminate(errorMessage);
				break;
			}
		}
		map.push_back(receivedMapRow);
	}
	if (!playerReceived)
		terminate("player location where not received!");
	return map;
}
/*----------------------------------------------------------------------------
 * The method .
 * input: .
 * output: .
*/
int BoardReader::receiveMapSize() {
	unsigned int size = 0;
	string charSize;
	this->m_boardReader >> charSize;
	for (int i = 0; i < charSize.size(); ++i) {
		if (!isdigit(charSize[i]))
			terminate("size receiving error!");
		size *= 10;
		size += charSize[i] - '0';
	}
	return size;
}
/*----------------------------------------------------------------------------
 * The method .
 * input: .
 * output: .
*/
void BoardReader::resetArgs() {
	this->m_primeCoinsLoc = this->m_primeEnemiesLoc = {};
	this->m_primePlayerLoc = Location();
}
