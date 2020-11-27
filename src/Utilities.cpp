#include <stdlib.h>
#include <fstream>
#include <iostream>

void terminate(const std::string &errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}