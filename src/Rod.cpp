#include "Location.h"
#include "Rod.h"

Rod::Rod(const Location& begin, const Location& end)
{
	Begin.col = begin.col;
	Begin.row = begin.row;
	End.col = end.row;
	End.row = end.row;
}