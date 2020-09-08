/*
 * SeedRecord.h
 *
 *  Created on: May 3, 2016
 *      Author: rogel
 */

#ifndef _SEEDREC_H
#define _SEEDREC_H

#include <string>
#include <vector>
using namespace std;

/*--------------------------------------------------------------------------------
 This is a class meant to store all information about a particular seed.
 It is HIGHLY RECOMMENDED to make use of the structure I have laid out,
 adding additional methods as needed.
 ---------------------------------------------------------------------------------*/

class SeedRecord {
private:
	// The seed string represented by this object.
	string seedStr;

	// An integer array, with one element for each ASCII value
	// from 0 to 127 (all printable characters).
	// The value in a given element represents how many times that
	// character occurred as the "next character" after the given
	// seedStr. For instance, charcounts['A'] holds the number of times
	// 'A' occured after the seedStr
	int charcounts[128];
	int total;

public:
	// Constructor
	SeedRecord(string s = "");

	// This just returns the seed string
	string GetSeed() const;

	// This displays information about the seed record in a
	// human-readable table.
	void Display() const;

	// This should pick a next character randomly, based on the relative
	// counts of each character in the charcounts array.
	char PickNextChar();

	void CharCount(char);

	// DON'T CHANGE THESE!
	// These allow SeedRecord objects to be used with standard STL containers
	// like maps and sets
	bool operator<(const SeedRecord & other) {
		return (this->seedStr < other.seedStr);
	}
	bool operator<(string str) {
		return (this->seedStr < str);
	}
	bool operator==(const SeedRecord & other) {
		return (this->seedStr == other.seedStr);
	}
	bool operator==(string str) {
		return (this->seedStr == str);
	}
};

#endif
