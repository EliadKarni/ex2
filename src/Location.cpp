#include "Location.h"

bool Location::operator==(const Location& location)const {
	return(this->col == location.col && this->row == location.row);
};