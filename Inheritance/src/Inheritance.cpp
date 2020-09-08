//============================================================================
// Name        : Inheritance.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Square.h"
int main() {
	Shape a("pentagon", "green");
	cout << "a: " << a.Description() << endl;
	Rectangle r(8, 6, "purple");
	cout << "r: " << r.Description() << endl << r.Area() << endl;
	cout << endl;
	Square s(5, "red");
	cout << s.Description() << endl << s.Area() << endl;

	return 0;
}
