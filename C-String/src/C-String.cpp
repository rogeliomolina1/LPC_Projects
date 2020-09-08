//============================================================================
// Name        : C-String.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;

int main() {
	char lname[33] = { ' ' };
	char searchString[33] = { ' ' };
	//int searchPosition = 0;
	char *searchResult;
	cout << "Please enter a simple string\n";
	cin.getline(lname, 32);
	cout << "You entered " << lname << endl;
	while (true) {
		cout << "Now, enter a small string to search for (end to exit)\n";
		cin.getline(searchString, 33);
		if (strcmp(searchString, "end") == 0) {
			break;
		} else {
		}
		searchResult = strstr(lname, searchString);
		cout << "Your search result is " << searchResult << "\n";
		strcpy(lname, searchResult);
		cout << "lname now has a value of: " << lname << endl;
	}
	cout << "Program ending";
	return 0;
}
