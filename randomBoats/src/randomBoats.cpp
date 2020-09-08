//============================================================================
// Name        : randomBoats.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;
void clearcin();

struct Boat {
	long boatID;			//4 bytes
	char manufacturer[30];  //30 bytes
	char modelName[30];     //30 bytes
	double length;          //8 bytes
	double width;           //8 bytes
};
int main() {
	long boatsToGenerate = 0;
	long boatToRead = 0;
	long boatsInFile = 0;
	string tempString;
	Boat tempBoat;
	vector<Boat> myBoats;
	fstream boatFile;

	//cout << "The size of a boat is: " << sizeof(Boat) << endl;

	cout << "How many boats would you like to generate\n";
	cin >> boatsToGenerate;
	clearcin();

	for (long i = 0; i < boatsToGenerate; i++) {
		tempBoat.boatID = i * 3;
		tempBoat.length = i * 2.13;
		tempBoat.width = i * 1.2;
		strcpy(tempBoat.manufacturer, "The Manuf");
		strcpy(tempBoat.modelName, "A Boat");
		myBoats.push_back(tempBoat);
	}           //for

	boatFile.open("boats.bin", ios::out | ios::binary | ios::app);

	for (unsigned long i = 0; i < myBoats.size(); i++) {
		boatFile.write(reinterpret_cast<char*>(&myBoats[i]), sizeof(Boat));
	}           //for
	boatFile.close();
	myBoats.clear();

	//Opening the file for input only
	boatFile.open("boats.bin", ios::in | ios::out | ios::binary);
	if (boatFile.fail()) {
		cout << "Error opening file\n";
	}           //if
	else {
		//This code will check to see how many boats are in the file
		boatFile.clear();
		boatFile.seekg(0L, ios::end);
		boatsInFile = (boatFile.tellg() / sizeof(Boat));
		cout << "There are " << boatsInFile << " boats in the file\n";
	}
	while (true) {
		cout << "Which boat would you like to read randomly\n";
		cin >> boatToRead;
		clearcin();
		if (boatToRead == -999)
			break;
		else if (boatToRead < 1) {
			cout << "Hey knucklehead-type in a valid boat #\n";
			continue;
		}           //if
		else {
			boatFile.clear();
			boatFile.seekg(((boatToRead - 1) * sizeof(Boat)), ios::beg);
			boatFile.read(reinterpret_cast<char*>(&tempBoat), sizeof(Boat));
			if (boatFile.eof()) {
				cout << "A boat with that identifier does not exist\n";
				continue;
			}           //if
			else {
				cout << "You read boat " << boatToRead << " with ID "
						<< tempBoat.boatID << " named " << tempBoat.modelName
						<< endl;
				cout
						<< "What would you like to change the boat's name to? (ENTER to make no change)\n";
				getline(cin, tempString);
				if (tempString.length() == 0) {
					continue;
				}           //if
				else {
					strcpy(tempBoat.modelName, tempString.c_str());
					boatFile.clear();
					boatFile.seekp(((boatToRead - 1) * sizeof(Boat)), ios::beg);
					boatFile.write(reinterpret_cast<char*>(&tempBoat),
							sizeof(Boat));
					if (boatFile.fail()) {
						cout << "Error writing the boat changes to the file\n";
					}           //if
					else {
					}           //else
				}           //else
			}           //else
		}           //else
	}           //while
	boatFile.close();
	cout << "Program is ending. Have a nice day!\n";

	return 0;
}

void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
}
