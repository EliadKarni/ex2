#pragma once
#include "Location.h"

class Coin {
private:
	Location Location;
	bool IsCollected = false;
public:
	Coin(const struct Location& Location);
};