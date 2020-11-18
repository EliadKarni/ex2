#pragma once
#include "Ladder.h"
#include "Location.h"

Ladder::Ladder(const Location& begin, const Location& end)
{
	Begin.col = begin.col;
	Begin.row = begin.row;
	End.col = end.col;
	End.row = end.row;
}