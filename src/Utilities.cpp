#pragma once
#include <stdlib.h>
#include <iostream>

void terminate(const std::string &errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}