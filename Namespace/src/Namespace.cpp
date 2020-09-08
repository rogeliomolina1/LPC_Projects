//============================================================================
// Name        : Namespace.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "utilities.hpp"

int main() {
	if (utilities::printMenu() == '9') {
		std::cout << "You are exiting\n";
		return 0;
	} else {
		std::cout << "Try again\n";
	}
	return 0;
}
