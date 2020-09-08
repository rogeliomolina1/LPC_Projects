//============================================================================
// Name        : hailstone_sequence.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void Transform(int&n);

int main() {
	int choice = 0;
	cout << "Enter a number: ";
	cin >> choice;
	cout << endl;
	while (choice > 1) {
		Transform(choice);
		if (choice % 2 == 0) {
			cout << choice << " is even\n";
		} else {
			cout << choice << " is odd\n";
		}
	}
	cout << "The value is now " << choice << endl;
	return 0;
}

void Transform(int&n) {
	if (n % 2 == 0) {
		n = n / 2;
	} else {
		n = (n * 3) + 1;
	}
}
