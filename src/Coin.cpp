#pragma once
#include "Coin.h"
#include "Location.h"

Coin::Coin(const struct Location& Location)
{
	this->Location.row = Location.row;
	this->Location.col = Location.col;
	this->IsCollected = false;
}


