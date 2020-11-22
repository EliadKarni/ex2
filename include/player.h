#pragma once
#include "Location.h"
#include "Map.h"

#define PLAYER_STAND_MODE '@'
#define PLAYER_CLIMB_MODE 'S'

class Player {
public:
	Player(Location location = Location(0, 0))
		: m_location(location) {}

	Location getLocation() const { return this->m_location; };
	void PlayTurn(const Map &map);
private:
	Location m_location;
};
