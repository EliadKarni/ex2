#pragma once
#include "Location.h"

#define PLAYER_STAND_MODE '@'
#define PLAYER_CLIMB_MODE 'S'

class Player {
public:
	Player(Location location = Location(0, 0))
		: m_location(location) {}

	Location getLocation();
private:
	Location m_location;
};
