#include "Location.h"

//========================================================================
/* The method compare the between the locations and returns if their equals.
 * input: Location wonted to be compared to.
 * output: if the locations equals.
*/
bool Location::operator==(const Location& location)const {
	return(this->col == location.col && this->row == location.row);
};
//========================================================================
/* The method check if the location exist in the rectangle
 * input: 2 vertices of rectangle in the map and some location.
 * output: true if the location exist in the rectangle.
*/
bool inRectangle(const Location& topLeft, const Location& botRight,
	const Location& location) {
	
	return(!(isAboveOf(location, topLeft) ||
		 isLeftOf(location, topLeft) ||
		isBelowOf(location, botRight) || 
		 isRightOf(location, botRight)));
}
//========================================================================
/* input: limit location and wanted location
 * output: true if the wanted location exist in left of the limit.
*/
bool isLeftOf(const Location& testLoc, const Location& loc) {
	return(loc.col > testLoc.col);
}
//========================================================================
/* input: limit location and wanted location
 * output: true if the wanted location exist in right of the limit.
*/
bool isRightOf(const Location& testLoc, const Location& loc) {
	return(!isLeftOf(testLoc,loc));
}
//========================================================================
/* input: limit location and wanted location
 * output: true if the wanted location exist in above of the limit.
*/
bool isAboveOf(const Location& testLoc, const Location& loc) {
	return(loc.row > testLoc.row);
}
//========================================================================
/* input: limit location and wanted location
 * output: true if the wanted location exist in below of the limit.
*/
bool isBelowOf(const Location& testLoc, const Location& loc) {
	return(!isAboveOf(testLoc, loc));
}
