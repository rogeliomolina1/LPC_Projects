/*
 * SeedRecord.cpp
 *
 *  Created on: May 3, 2016
 *      Author: rogel
 */

#include "SeedRecord.h"
#include "utils.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

SeedRecord::SeedRecord(string s) {
	// This is ALREADY COMPLETE.
	seedStr = s;
	for (int i = 0; i < 128; i++)
		charcounts[i] = 0;
	total = 0;
}

string SeedRecord::GetSeed() const {
	// This is ALREADY COMPLETE.
	return seedStr;
}

void SeedRecord::Display() const {
	// This is ALREADY COMPLETE.
	int sum = 0;
	for (int i = 0; i < 128; i++)
		sum += charcounts[i];

	cout << "Character frequency after '" << seedStr << "':\n";
	for (int i = 0; i < 128; i++) {
		if (charcounts[i] > 0) {
			cout << setw(6) << charcounts[i] << setw(10)
					<< (charcounts[i] / (float) sum) * 100 << "%   '" << char(i)
					<< "'" << endl;
		}
	}
}

void SeedRecord::CharCount(char record) {
	charcounts[record]++;
	total++;

}
// This should pick a next character randomly, based on the relative
// counts of each character in the charcounts array.
char SeedRecord::PickNextChar() {
	// This is NOT COMPLETE.
	// The return value here is just a placeholder. You should eventually erase this line:
	string helperString;
	for (int j = 0; j < 128; j++) {
		for (int i = 0; i < charcounts[j]; i++) {
			helperString += j;
		}
	}
	if (total != 0)
		return helperString[rand() % helperString.length()];
	else
		return ('\0');
}
