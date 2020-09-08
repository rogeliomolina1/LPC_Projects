/*
 * recursive.h
 *
 *  Created on: Sep 17, 2016
 *      Author: rogel
 */

#ifndef RECURSIVE_H_
#define RECURSIVE_H_

#include <iostream>
using namespace std;

bool IsPowerOfTwo(int n);
/// Determines if n is an exact power of 2
/// (For instance, 2, 8, 128, 1024)
/// *** You may not use pow()

string ReplaceEsWithAs(string s);
/// Return a string that is identical to s
/// except that any 'e' is replaced with an 'a'
/// (Assume all characters are lowercase.)

int DigitSum(int n);
/// Return the sum of the digits in n
/// (See p. 350, #7 for hints.)

#endif /* RECURSIVE_H_ */
