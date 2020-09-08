//============================================================================
// Name        : PrimeProject.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

void ShowAllPrimes(int start, int stop);

bool IsPrime(int n);

int main() {
	int low, high;
	cout << "Give me a range of numbers...\n";
	cout << "From: ";
	cin >> low;
	cout << "To: ";
	cin >> high;
	ShowAllPrimes(low, high);
	return 0;
}

void ShowAllPrimes(int start, int stop) {
	for (int x = start; x <= stop; x++) {
		if (IsPrime(x))
			cout << x << " is prime." << endl;
	}
}

bool IsPrime(int n) {
	for (int k = 2; k <= n / 2; k++) {
		if (n % k == 0)
			return false;
	}
	return true;
}
