/*
 * RandomWriter.cpp
 *
 *  Created on: May 3, 2016
 *      Author: rogel
 */

#include "RandomWriter.h"
#include "utils.h"
using namespace std;

RandomWriter::RandomWriter() {
	/// This is ALREADY COMPLETE.
	kvalue = 0;
	fullText = "";
	filename = "";
	length = 30;
}

void RandomWriter::SetLength(int length) {
	this->length = length;
	/// TO DO:
	/// Perform any additional processing needed because the length has changed.
}

void RandomWriter::SetFilename(string filename) {
	string text = GetFullFile(filename);
	if (text != "") {
		fullText = text;
		this->filename = filename;
	}
	/// TO DO:
	/// Perform any additional processing needed because the source text has changed.

}

void RandomWriter::SetKValue(int kvalue) {
	this->kvalue = kvalue;
	/// TO DO:
	/// Perform any additional processing needed because the k value has changed.
}

string RandomWriter::GetFilename() const {
	return filename;
}

int RandomWriter::GetKValue() const {
	return kvalue;
}

int RandomWriter::GetLength() const {
	return length;
}

/// this is a test.

void RandomWriter::CalculateSeeds() {
	for (unsigned int i = 0; i < (fullText.length() - (GetKValue() + 1)); i++) {
		string currentSeed = fullText.substr(i, GetKValue());

		if (seedMap.find(currentSeed) == seedMap.end()) {
			SeedRecord record(currentSeed);
			seedMap[currentSeed] = record;
			seedMap[currentSeed].CharCount(fullText[i + GetKValue()]);
		} else {
			seedMap[currentSeed].CharCount(fullText[i + GetKValue()]);
		}
	}
}

void RandomWriter::GenerateRandomOutput() {
	/// TO DO:
	/// Produce random output according to the procedure described in the assignment,
	/// based on the current kvalue and length.
	///
	/// Hint: this will probably mean using internal data that you have already set up
	///  by the time this method is called.
	CalculateSeeds();
	string firstSeed;
	firstSeed = fullText.substr(rand() % (fullText.length() - GetKValue() - 1),
			kvalue);
	cout << firstSeed;
	for (int i = 0; i < (length); i++) {
		char NextChar = seedMap[firstSeed].PickNextChar();
		if (NextChar == '\0') {
			firstSeed = fullText.substr(
					rand() % (fullText.length() - GetKValue() - 1), kvalue);
		} else {
			cout << NextChar;
			firstSeed = firstSeed + NextChar;
			firstSeed = firstSeed.substr(1);
		}
	}
}
