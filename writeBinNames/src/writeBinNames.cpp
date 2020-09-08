//============================================================================
// Name        : writeBinNames.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
	fstream yourFile;
	string stringInput;
	char myCString[35];

	yourFile.open("aFile.bin", ios::out | ios::app | ios::binary);
	if (yourFile.fail()) {
		cout << "File open for output failed, program ending\n";
		return 0;
	} else {
		cout << "File opened for output successfully\n";
		while (true) {
			cout << "Enter a string to write to the file: ";
			getline(cin, stringInput);
			if (stringInput.length() <= 0) {
				continue;
			} else if (stringInput == "-999") {
				break;
			} else {
			}
			//yourFile << stringInput << endl;
			strcpy(myCString, stringInput.c_str());
			yourFile.write(reinterpret_cast<char*>(&myCString),
					sizeof(myCString));
		}
	}

	yourFile.close();

	cout << "Program Ending, Have a Great Day\n" << endl;
	return 0;
}
