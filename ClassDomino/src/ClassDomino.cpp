//============================================================================
// Name        : ClassDomino.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "domino.h"

int main() {
	Domino a;
	cout << a.getLeftDots() << endl;
	cout << a.getRightDots() << endl;
	cout << a.toString() << endl;
	a.flip();
	cout << a.getLeftDots() << endl;
	cout << a.getRightDots() << endl;
	cout << a.toString() << endl;
	Domino b(3, 6);
	cout << b.getLeftDots() << endl;
	cout << b.getRightDots() << endl;
	cout << b.toString() << endl;
	b.flip();
	cout << b.getLeftDots() << endl;
	cout << b.getRightDots() << endl;
	cout << b.toString() << endl;
	return 0;
}
