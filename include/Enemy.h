#pragma once
#include "Location.h"

#define ENEMY_SYMB '%'

class Enemy {
public:
	Enemy(Location location = Location(0, 0)) : m_location(location) {}

	void setLocation(const Location& newlocation);
	Location getLocation();
private:
	Location m_location;

};