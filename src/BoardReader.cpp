#pragma once
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
	this->m_boardReader.open(BOARD_PATH);
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
Map BoardReader::readNextLevel() {
	vector<vector<char>> map;
	bool playerReceived = false;
	std::string receivedline;
	char receivedChar;
	int size = receiveMapSize();

	Location playerLoc;
	vector<Location> enemysLocs;
	vector<Location> coinsLocs;

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
				playerLoc = Location(i, j);
				receivedMapRow.push_back(NOTHING);
				break;
			case PLAYER_CLIME:
				if (playerReceived)
					terminate("player received twice!");
				playerReceived = true;
				playerLoc = Location(i, j);
				receivedMapRow.push_back(NOTHING);
				break;
			case ENEMY:
				enemysLocs.push_back(Location(i, j));
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
				coinsLocs.push_back(Location(i, j));
				receivedMapRow.push_back(NOTHING);
				break;
			default:
				std::string errorMessage = "receiving the char ";
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
	return Map(map, playerLoc, coinsLocs, enemysLocs);
}
/*----------------------------------------------------------------------------
 * The method .
 * input: .
 * output: .
*/
int BoardReader::receiveMapSize() {
	unsigned int size = 0;
	std::string charSize;
	this->m_boardReader >> charSize;
	for (int i = 0; i < charSize.size(); ++i) {
		if (!isdigit(charSize[i]))
			terminate("size receiving error!");
		size *= 10;
		size += charSize[i] - '0';
	}
	return size;
}