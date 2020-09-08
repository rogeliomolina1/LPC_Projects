//============================================================================
// Name        : HashTableImplementation.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "HashTable.h"

int main() {
	HashTable test;
	test.Insert("pizza");
	test.Insert("spaghetti");
	test.Insert("salmon");
	test.Insert("wings");
	test.Insert("burger");
	test.Insert("chips");
	test.Insert("steak");
	test.Insert("veal");
	test.Insert("beef");

	cout << endl;
	if (test.Find("pizza")) {
		cout << "Found pizza" << endl;
	} else {
		cout << "No pizza" << endl;
	}
	if (test.Find("salmon")) {
		cout << "Found salmon" << endl;
	} else {
		cout << "No salmon" << endl;
	}
	if (test.Find("burger")) {
		cout << "Found burger" << endl;
	} else {
		cout << "No candy" << endl;
	}
	if (test.Find("spaghetti")) {
		cout << "Found spaghetti" << endl;
	} else {
		cout << "No spaghetti" << endl;
	}
	if (test.Find("wings")) {
		cout << "Found wings" << endl;
	} else {
		cout << "No wings" << endl;
	}
	cout << endl;
	test.Remove("chips");
	test.Remove("burger");
	cout << endl;
	if (test.Find("pizza")) {
		cout << "Found pizza" << endl;
	} else {
		cout << "No pizza" << endl;
	}
	if (test.Find("salmon")) {
		cout << "Found salmon" << endl;
	} else {
		cout << "No salmon" << endl;
	}
	if (test.Find("burger")) {
		cout << "Found burger" << endl;
	} else {
		cout << "No candy" << endl;
	}
	if (test.Find("spaghetti")) {
		cout << "Found spaghetti" << endl;
	} else {
		cout << "No spaghetti" << endl;
	}
	if (test.Find("chips")) {
		cout << "Found chips" << endl;
	} else {
		cout << "No chips" << endl;
	}
	cout << endl;
	test.Insert("chips");
	test.Insert("burger");

	cout << endl;
	if (test.Find("pizza")) {
		cout << "Found pizza" << endl;
	} else {
		cout << "No pizza" << endl;
	}
	if (test.Find("salmon")) {
		cout << "Found salmon" << endl;
	} else {
		cout << "No salmon" << endl;
	}
	if (test.Find("burger")) {
		cout << "Found burger" << endl;
	} else {
		cout << "No burger" << endl;
	}
	if (test.Find("spaghetti")) {
		cout << "Found spaghetti" << endl;
	} else {
		cout << "No spaghetti" << endl;
	}
	if (test.Find("chips")) {
		cout << "Found chips" << endl;
	} else {
		cout << "No chips" << endl;
	}
	cout << endl;
	test.Remove("beef");
	cout << endl;
	if (test.Find("beef")) {
		cout << "Found beef" << endl;
	} else {
		cout << "No beef" << endl;
	}
	cout << endl;
	test.Insert("beef");
	cout << endl;
	if (test.Find("beef")) {
		cout << "Found beef" << endl;
	} else {
		cout << "No beef" << endl;
	}
	return 0;
}
