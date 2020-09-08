/*
 * recursive.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: rogel
 */

#include "recursive.h"

bool IsPowerOfTwo(int n) {
/// Determines if n is an exact power of 2
/// (For instance: 2, 8, 128, and 1024)
	if (n == 2) {
		return true;
	} else if (n < 2) {
		return false;
	} else if (n % 2 != 0) {
		return false;
	} else {
		return (IsPowerOfTwo(n / 2));
	}
}

string ReplaceEsWithAs(string s) {
/// Return a string that is identical to s
/// except that any 'e' is replaced with an 'a'
/// (Assume all characters are lowercase.)
	if (s.length() < 1)
		return s;
	if (s[0] == 'e') {
		s = 'a' + s.substr(1);
	}
	return (s[0] + ReplaceEsWithAs(s.substr(1, s.length())));

}

int DigitSum(int n) {
/// Return the SUM of all digits in n
	if (n == 0) {
		return n;
	} else {
		return (n % 10 + DigitSum(n / 10));
	}
}
