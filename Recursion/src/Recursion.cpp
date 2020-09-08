//============================================================================
// Name        : Recursion.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int Factorial(int n) {
	if (n <= 1) {
		return 1;
	} else {
		return (n * (Factorial(n - 1)));
	}
}

int Mult(int x, int y) {
	if (y == 0) {
		return 0;
	} else {
		return (x + (Mult(x, (y - 1))));
	}
}

int Pow(int x, int y) {
	if (y == 0) {
		return 1;
	} else {
		return (x * (Mult(x, (y - 1))));
	}
}

bool Divisible(int x, int y) {
	if (x == 0) {
		return true;
	} else if (x < y) {
		return false;
	} else {
		return (Divisible(y, x - y));
	}
}

string Reverse(string str) {
	if (str.length() <= 1) {
		return str;
	} else {
		return (Reverse(str.substr(1)) + str[0]);;
	}
}

bool IsPalindrome(string str) {
	if (str.length() <= 1) {
		return true;
	} else if (str[0] != str[str.length() - 1]) {
		return false;
	} else {
		return IsPalindrome(str.substr(1, str.length() - 2));
	}
}
int main() {
	cout << Factorial(10) << endl;
	cout << Mult(3, 10) << endl;
	cout << Pow(2, 3) << endl;
	if (!Divisible(10, 5)) {
		cout << "False" << endl;
	} else {
		cout << "True" << endl;
	}
	cout << Reverse("pie") << endl;
	if (!IsPalindrome("racecar")) {
		cout << "False" << endl;
	} else {
		cout << "True" << endl;
	}
	return 0;
}

