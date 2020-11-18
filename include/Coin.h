#pragma once
#include "Location.h"

class Coin {
private:
	Location Location;
	bool IsCollected = false; // I prefer delete it from the list
public:
	Coin(const struct Location& Location); //why by reference? the Board will be deleted due the controller build
};