//============================================================================
// Name        : readBinNames.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

bool openAFile(fstream&, string);
string readAFile(fstream&);

int main() {
	fstream yourFile;
	string stringInput;
	string fileName;
	int recordCount = 0;

	cout << "What file would you like to read from: ";
	getline(cin, fileName);
	if (fileName.length() <= 0) {
		cout << "Invalid input\n";
		return 0;
	}

	if (!openAFile(yourFile, fileName)) {
		return 0;
	} else {
		while (true) {
			//yourFile >> stringInput;
			stringInput = readAFile(yourFile);
			if (yourFile.eof()) {
				break;
			} //if
			else {
			} //else
			cout << "String read from file: " << stringInput << endl;
			recordCount++;
		} //while
	} //else

	cout << "Total records read is: " << recordCount << endl;
	yourFile.close();
	cout << "Program Ending, Have a Great Day\n" << endl;
	return 0;
} //main
bool openAFile(fstream &aFile, string fileName) {
	aFile.open(fileName.c_str(), ios::in | ios::binary);
	if (aFile.fail()) {
		cout << "File does not exist, try again later\n";
		return false;
	} //if
	else {
		cout << "File exists, open successful\n";
		return true;
	}
}

string readAFile(fstream & aFile) {
	string aString;
	char aCString[35];
	aFile.read(reinterpret_cast<char*>(&aCString), sizeof(aCString));
	if (aFile.eof()) {
		return aString;
	} //if
	else if (aFile.fail()) {
		cout << "Internal file input error\n";
	} //if
	aString = aCString;
	return aString;
}
