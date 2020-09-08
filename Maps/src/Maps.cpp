//============================================================================
// Name        : Maps.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, double> menuMap;

	/// insert entries
	menuMap["pizza"] = 3.75;
	menuMap["coffee"] = 1.85;
	menuMap["burrito"] = 6.25;

	/// update an entry
	menuMap["coffee"] = 2.25;

	/// looping through
	map<string, double>::iterator iter;
	for (iter = menuMap.begin(); iter != menuMap.end(); iter++) {
		cout << iter->first; /// key
		cout << " ";
		cout << iter->second; /// value
		cout << "\n";
	}

	double total = 0.0;
	string item = "";
	while (true) {
		cout << "Enter a menu item: ";
		getline(cin, item);

		/// Search for a key
		if (menuMap.find(item) == menuMap.end()) {
			cout << "Sorry, we have no " << item << " here!\n";
		} else {
			cout << "Ok, adding that to your total.\n";
			total += menuMap[item];
			cout << "Your total is now $" << total << endl;
		}
	}
}
