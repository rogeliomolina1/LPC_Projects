//============================================================================
// Name        : OperatorOverloading.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "PairValue.h"

int main() {
	PairValue a(3, 7);
	cout << a; // should print "(3, 7)"

	PairValue b(3, 5);
	PairValue c(1, 2);
	PairValue d = b + c;
	cout << d; // should print "(4, 7)"
	PairValue e = b - c;
	cout << e; // should print "(2, 3)"

	PairValue f(3, 5);
	PairValue g(1.5, 2);
	cout << (f * g); // should print "14.5"

	PairValue h(5, 4);
	PairValue answer = h * 1.5;
	cout << answer; // should print "(7.5, 6)"

	PairValue i(1, 3);
	PairValue j(4, 7);
	double k = i % j;
	cout << k; // should print "5"

	PairValue p(7, 3);
	++p;
	cout << p; // would print "(-3, 7)"

	PairValue r(5, 4);
	double area = r;
	cout << area << endl; // would print "20"
	return 0;
}
