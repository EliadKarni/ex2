#pragma once
#include "Location.h"

#define PLAYER_STAND_MODE '@'
#define PLAYER_CLIMB_MODE 'S'

class Player {
public:
	Player(Location location = Location(0, 0), char mode = PLAYER_STAND_MODE)
		: m_location(location), m_playerMode(mode) {}

	Location getLocation();
	char getMod();
private:
	Location m_location;
	char m_playerMode;
};
