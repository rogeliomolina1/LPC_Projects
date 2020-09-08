/*
 * utilities.hpp
 *
 *  Created on: Nov 3, 2015
 *      Author: student
 */

#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_
#include <iostream>
using namespace std;

void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
} //clearCin

string enterString(string prompt, unsigned int min, unsigned int max) {
	bool keepGoing = true;
	string aString;
	while (keepGoing) {
		cout << prompt << endl;
		getline(cin, aString);
		if (aString.length() <= min || aString.length() > max) {
			cout << "Invalid Input\n";
		} else {
			keepGoing = false;
		} //else
	} //while
	return aString;
} //enterString
double enterDouble(string prompt, double min, double max) {
	double num = 0;
	while (true) {
		cout << prompt << endl;
		cin >> num;
		clearcin();
		if (num < min || num > max) {
			cout << "Invalid Input\n";
		} else {
			break;
		} //else
	} //while
	return num;
} //enterDouble
double average(double anArray[], int theSize) {
	double average = 0;
	double sum = 0;
	for (int ctr = 0; ctr < theSize; ctr++) {
		sum = sum + anArray[ctr];
		average = (sum / theSize);
	} //for
	return average;
} //average
int enterInt(string prompt, int min, int max) {
	int num = 0;
	while (true) {
		cout << prompt << endl;
		cin >> num;
		clearcin();
		if (num < min || num > max) {
			cout << "Invalid Input\n";
		} else {
			break;
		} //else
	} //while
	return num;
} //enterDouble

#endif /* UTILITIES_HPP_ */
