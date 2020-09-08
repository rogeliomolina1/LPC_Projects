/*
 * utils.h
 *
 *  Created on: May 3, 2016
 *      Author: rogel
 */

#ifndef _UTILS_H
#define _UTILS_H
#include <iostream>
using namespace std;

/***
 This is a list of functions that you will probably find useful in completing
 the assignment. They are already implemented for you.
 ***/

// Converts the given integer into the equivalent integer value
// (For instance, passing in the string "42" will produce a return value of 42.)
int ConvertStringToInt(string s);

// Returns an all-lowercase version of the given string
string ConvertStringToLowercase(string s);

// Reads an entire file into a string, then returns the string.
// Prints an error and returns empty string if the file can't be opened.
string GetFullFile(string filename);

// Returns a random integer between low and high (inclusive)
// ex: RandomInteger (3, 5) randomly returns 3, 4 or 5.
int RandomInteger(int low, int high);

// Returns a random non-integer between low and high
double RandomDouble(double low, double high);

// Returns the outcome of a "random-chance event" having probability p,
// where p is between 0 and 1.
// Ex: RandomChance(0.5) will return true about half of the times it is called.
// Ex: RandomChance(0.1) will return true about 1/10 the times it is called.
bool RandomChance(double p);

#endif
