#pragma once
#include "Location.h"

#define ENEMY_SYMB '%'

class Enemy {
public:
	Enemy(Location location = Location(0, 0)) : m_location(location) {}

	Location getLocation();
	void autoTurn(const Location &playerLocation);
private:
	Location m_location;

};