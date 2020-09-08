//============================================================================
// Name        : BSTImplementation.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CS20Map.h"

int main() {
	BST<MapEntry<string, int> > food;

	BST<string> mytree;

	mytree.Insert("E");
	mytree.Insert("B");
	mytree.Insert("F");
	mytree.Insert("C");
	mytree.Insert("D");
	mytree.Insert("A");
	mytree.Insert("G");

	cout << endl;

	mytree.PrintAll();

	mytree.Remove("E");
	cout << endl;
	mytree.PrintAll();
	mytree.Remove("B");
	cout << endl;
	mytree.PrintAll();
	mytree.Remove("F");
	cout << endl;
	mytree.PrintAll();
	mytree.Remove("C");
	cout << endl;
	mytree.PrintAll();
	mytree.Remove("D");
	cout << endl;
	mytree.PrintAll();
	mytree.Remove("A");
	cout << endl;
	mytree.PrintAll();
	mytree.Remove("G");
	cout << endl;
	mytree.PrintAll();
	return 0;
}
