//============================================================================
// Name        : computing_pi_using_taylorseries.cpp
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

int main() {
	int terms = 0;
	terms = ChooseTerms();
	double result = 0;
	result = CalculateSeries(terms);
	cout << result;
	return 0;
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
