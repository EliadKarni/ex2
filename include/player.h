#pragma once
#include "Location.h"

#define STAND_MODE '@'
#define CLIMB_MODE 'S'

class Player {
public:
	Player(Location location = Location(0, 0), char mode = STAND_MODE)
		: m_location(location), m_playerMode(mode) {}

	Location getLocation();
	char getMod();
	void userTurn();
private:
	Location m_location;
	char m_playerMode;
};
