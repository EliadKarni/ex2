#pragma once
#include "Location.h"
#include "Map.h"


class Enemy {
public:
	//------------------------- constractors section -------------------------

	Enemy(Location location = Location(0, 0)) : m_location(location) {}
	//-------------------------- gets section --------------------------------

	Location getLocation()const;
	//------------------------- method section -------------------------------

	void playTurn(const Map &map, const Location &playerLocation);
private:
	Location m_location;
};