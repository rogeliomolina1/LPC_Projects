/*
 * RandomWriter.h
 *
 *  Created on: May 3, 2016
 *      Author: rogel
 */

#include "SeedRecord.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <map>
using namespace std;

/***''
 This is the main class that handles processing of the source text and
 generating random-writing output.  Please read the descriptions of
 each method carefully, and make sure to ask questions if anything
 is unclear.
 ***/

class RandomWriter {
private:
	/***
	 The four instance variables below are just the MINIMUM set of variables
	 needed. You should definitely add more as you figure out how you are going
	 to store the data you need for everything to work.
	 ***/
	string filename;
	string fullText;
	int kvalue;
	int length;
	map<string, SeedRecord> seedMap;

public:
	// Constructor
	RandomWriter();

	/// Simple getters for private variables
	void SetFilename(string filename);
	void SetKValue(int kvalue);
	void SetLength(int length);

	/// Simple setters for private variables
	string GetFilename() const;
	int GetKValue() const;
	int GetLength() const;

	void CalculateSeeds();

	/// Generate random output using current settings
	void GenerateRandomOutput();
};
