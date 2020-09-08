//============================================================================
// Name        : GCD.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (x % y == 0) {
		return y;
	} else {
		return (gcd(y, x % y));
	}
}

int main() {
	cout << gcd(20, 15);
	cout << endl;
	cout << gcd(21, 9);
	return 0;
}
