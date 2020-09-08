//============================================================================
// Name        : STL_set.cpp
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
	set<string> things;

	things.insert("cat");
	things.insert("rhino");
	things.insert("owl");
	things.insert("potato");
	things.insert("dinner fork");
	things.insert("spork");
	things.insert("wheel of cheese");
	things.insert("cake");
	things.insert("owl");

	cout << things.size() << endl;

	for (set<string>::iterator iter = things.begin(); iter != things.end();
			iter++) {
		cout << *iter << endl;
	}

	while (true) {
		cout << "Enter a thing: ";
		string thing;
		getline(cin, thing);

		if (things.find(thing) != things.end())
			cout << "Yes, we have a " << thing << endl;
		else
			cout << "No, we do not have any " << thing << endl;
	}
	return 0;
}

