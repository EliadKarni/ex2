#include <stdlib.h>
#include <iostream>
#include "Utilities.h"

void terminate(const std::string &errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}
