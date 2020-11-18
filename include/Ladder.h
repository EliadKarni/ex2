#pragma once
#include "Location.h"
class Ladder {
private:
	Location Begin, End;
public:
	Ladder(const Location& begin,const Location& end);
};