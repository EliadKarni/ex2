#pragma once
#include "Location.h"

class Player {
public:
	Player(Location lcation = Location(0,0));

	Location getLocation();
	void playerTurn();
private:
	Location m_location;
};
