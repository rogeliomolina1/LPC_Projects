//============================================================================
// Name        : Decomposition_A.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double ChooseTerms();

double CalculateSeries(int terms);

void Transform(int&n);

int main() {
	////////////////////////////////////////////////////////////////
	//#10
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
	/////////////////////////////////////////////////////////////////
	//#11
	int terms = 0;
	terms = ChooseTerms();
	double result = 0;
	result = CalculateSeries(terms);
	cout << result;
	return 0;
}

void Transform(int&n) {
	if (n % 2 == 0) {
		n = n / 2;
	} else {
		n = (n * 3) + 1;
	}
}

double ChooseTerms() {
	int terms;
	cout << "How many terms would you like to use\n";
	cin >> terms;
	return terms;
}

double CalculateSeries(int terms) {
	double result;
	for (int n = 0; n < terms; n++) {
		double numerator = pow((-1), n);
		result = result + ((numerator) * 4) / ((2 * n) + 1);
	}
	return result;
}

//Calculus
//(-1)^i/2i+1

