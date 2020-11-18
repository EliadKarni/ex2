#pragma once
#include "Location.h"
class Rod
{
public:
	Rod(const Location& begin, const Location& end);
private:
	Location Begin, End;
};
