#include "Location.h"

//========================================================================
 * The method compare the between the locations and returns if their equals.
 * input: Location wonted to be compared to.
 * output: if the locations equals.
*/
bool Location::operator==(const Location& location)const {
	return(this->col == location.col && this->row == location.row);
};
//========================================================================
 * The method 
 * input: .
 * output: .
*/
bool inRectangle(const Location& topLeft, const Location& botRight,
	const Location& location) {
	bool above = isAboveOf(location, topLeft),
		blow = isBelowOf(location, botRight),
		left = isLeftOf(location, topLeft),
		right = isRightOf(location, botRight);
	return(!(isAboveOf(location, topLeft) ||
		 isLeftOf(location, topLeft) ||
		isBelowOf(location, botRight) || 
		 isRightOf(location, botRight)));
}
//========================================================================
bool isLeftOf(const Location& testLoc, const Location& loc) {
	return(loc.col > testLoc.col);
}
//========================================================================
bool isRightOf(const Location& testLoc, const Location& loc) {
	return(!isLeftOf(testLoc,loc));
}
//========================================================================
bool isAboveOf(const Location& testLoc, const Location& loc) {
	return(loc.row > testLoc.row);
}
//========================================================================
bool isBelowOf(const Location& testLoc, const Location& loc) {
	return(!isAboveOf(testLoc, loc));
}
