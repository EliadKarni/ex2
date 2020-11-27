#pragma once
#include "Location.h"
#include "Map.h"

class Player {
public:
	//------------------------- constractors section -------------------------

	Player(Location location = Location(0, 0))
		: m_location(location) {}
	//-------------------------- gets section --------------------------------

	Location getLocation() const { return this->m_location; };
	//------------------------- method section -------------------------------

	void PlayTurn(const Map &map);
private:
	Location m_location;
};
