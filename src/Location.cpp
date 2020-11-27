#include "Location.h"

/*----------------------------------------------------------------------------
 * The method compare the between the locations and returns if their equals.
 * input: Location wonted to be compared to.
 * output: if the locations equals.
*/
bool Location::operator==(const Location& location)const {
	return(this->col == location.col && this->row == location.row);
};