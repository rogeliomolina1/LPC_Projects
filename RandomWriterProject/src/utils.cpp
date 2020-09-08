/*
 * utils.cpp
 *
 *  Created on: May 3, 2016
 *      Author: rogel
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstdlib>
using namespace std;

int ConvertStringToInt(string s) {
	stringstream ss;
	int result;
	ss << s;
	ss >> result;
	if (!ss) {
		cerr << "*** Fatal error: Attempt to convert '" << s << "' to an int\n";
		exit(-1);
	}
	return result;
}

string ConvertStringToLowercase(string s) {
	for (unsigned int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
	return s;
}

int RandomInteger(int low, int high) {
	return (rand() % (1 + high - low) + low);
}

double RandomDouble(double low, double high) {
	double val = rand();
	double fraction = val / (RAND_MAX);
	return (fraction * (high - low) + low);
}

bool RandomChance(double p) {
	return (RandomDouble(0.0, 1.0) <= p);
}

string GetFullFile(string filename) {
	string text;
	ifstream infile(filename.c_str());
	if (!infile) {
		cout << "*** Could not open file '" + filename + "'\n";
		return ("");
	}

	char c;
	infile.read(&c, 1);
	do {
		text += c;
		infile.read(&c, 1);
	} while (infile);

	return (text);
}
