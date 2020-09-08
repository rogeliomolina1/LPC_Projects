/*
 * utilities.cpp
 *
 *  Created on: Nov 12, 2015
 *      Author: student
 */
#include "utilities.hpp"

void utilities::cinclear() {
	std::cin.clear();
	std::cin.ignore(32768, '\n');
}
char utilities::printMenu() {
	char userResponse = '\0';
	while (true) {
		std::cout << "Welcome to my Student Management Program\n";
		std::cout << "========================================\n";
		std::cout << " 1. Add a New Student\n";
		std::cout << " 3. Print Student Grade Report\n";
		std::cout << " 4. Clear Student Data\n";
		std::cout << " 5. Write Student Data to StudentGrades.txt (disabled)\n";
		std::cout << " 6. Read Student Data From StudentGrades.txt(disabled)\n";
		std::cout << " 9. Exit Program\n";
		std::cout << "\nPlease Enter a Menu Option:\n";
		std::cin >> userResponse;
		if (userResponse != '1' && userResponse != '3' && userResponse != '4'
				&& userResponse != '9') {
			std::cout << "Input Error, please try again\n";
		} //if
	} //while
	return userResponse;
}

