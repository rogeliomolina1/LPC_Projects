//============================================================================
// Name        : BoyGirlSet.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	set<string> boys;
	boys.insert("john");
	boys.insert("ralf");
	boys.insert("zack");
	boys.insert("andrew");

	set<string> girls;
	girls.insert("rebecca");
	girls.insert("stacy");
	girls.insert("joanne");
	girls.insert("claudia");

	while (true) {
		cout << "Enter a name: ";
		string name;
		cin >> name;

		if (boys.find(name) != boys.end() && girls.find(name) != girls.end())
			cout << "This is a boy and girl name " << endl;
		else if (girls.find(name) != girls.end())
			cout << "This is a girl name " << endl;
		else if (boys.find(name) != boys.end())
			cout << "This is a boy name " << endl;
		else {
			cout
					<< "Name unknown. Please enter a gender for the name (boy, girl, or both)"
					<< endl;
			string answer;
			cin >> answer;
			if (answer == "boy") {
				boys.insert(name);
			} else if (answer == "girl") {
				girls.insert(name);
			} else {
				boys.insert(name);
				girls.insert(name);
			}
		}
	}
	return 0;
}

