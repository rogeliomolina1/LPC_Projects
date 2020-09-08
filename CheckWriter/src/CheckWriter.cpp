//============================================================================
// Name        : CheckWriter.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
void convert(long long int);
int main() {
	long long int num;
	while (true) {
		cout << "Enter a number (0 to exit): ";
		cin >> num;
		cin.clear();
		cin.ignore(32768, '\n');
		if (num == 0) {
			break;
		} else if (num > 3999999999) {
			cout << "This number is too large\n";
			continue;
		} else if (num < 0) {
			cout << "Number is negative\n";
			continue;
		} else {
			convert(num);
			cout << endl << endl;
		}
	}
}
void convert(long long int value) {
	const char * const ones[20] = { "zero", "one", "two", "three", "four",
			"five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
			"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
			"eighteen", "nineteen" };
	const char * const tens[10] = { "", "ten", "twenty", "thirty", "forty",
			"fifty", "sixty", "seventy", "eighty", "ninety" };

	if (value >= 1000000000) {
		convert(value / 1000000000);
		cout << " billion";
		if (value % 1000000000) {
			cout << " ";
			convert(value % 1000000000);
		}
	} else if (value >= 1000000) {
		convert(value / 1000000);
		cout << " million";
		if (value % 1000) {
			cout << " ";
			convert(value % 1000000);
		}
	} else if (value >= 1000) {
		convert(value / 1000);
		cout << " thousand";
		if (value % 1000) {
			cout << " ";
			convert(value % 1000);
		}
	} else if (value >= 100) {
		convert(value / 100);
		cout << " hundred";
		if (value % 100) {
			cout << " ";
			convert(value % 100);
		}
	} else if (value >= 20) {
		cout << tens[value / 10];
		if (value % 10) {
			cout << " ";
			convert(value % 10);
		}
	} else {
		cout << ones[value];
	}
	return;
}
