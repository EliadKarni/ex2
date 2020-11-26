#pragma once
#include "Location.h"
#include "Map.h"


class Enemy {
public:
	Enemy(Location location = Location(0, 0)) : m_location(location) {}

	Location getLocation()const;
	void setLocation(const Location& newlocation);
	void playTurn(const Map &map, const Location &playerLocation);
private:
	Location m_location;
};