#pragma once
#include "Location.h"

class Enemy {
public:
	Enemy(Location lcation = Location(0, 0));

	Location getLocation();
	void playerTurn(const Location &playerLocation);
private:
	Location m_location;
};
