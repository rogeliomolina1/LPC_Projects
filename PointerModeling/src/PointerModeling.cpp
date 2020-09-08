//============================================================================
// Name        : PointerModeling.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Rectangle.h"
#include "Color.h"

int main() {
	Rectangle a(4, 6);
	a.setFill(0, 0, 0);
	/// Rectangle b = a;
	/// ^
	/// |
	/// This really means:
	Rectangle b(a);

	cout << "a: " << a.Description() << endl;
	cout << "b: " << b.Description() << endl;

	Rectangle*p = new Rectangle(3, 5);
	p->setFill(0, 0, 0);
	delete p;
	return 0;
}
