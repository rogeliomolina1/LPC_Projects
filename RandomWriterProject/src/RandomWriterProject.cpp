//============================================================================
// Name        : RandomWriterProject.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
#include "RandomWriter.h"
#include "utils.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

void Menu(int current_kvalue, int current_length, string current_filename);
void HandleAction(RandomWriter & rw, string choice);

int main() {
	/// This is ALREADY COMPLETE.
	/// Set up randomization
	srand(time(0));
	rand();
	string input;
	RandomWriter theRandomWriter;
	while (true) {
		Menu(theRandomWriter.GetKValue(), theRandomWriter.GetLength(),
				theRandomWriter.GetFilename());
		cout << "\n> ";
		getline(cin, input);
		input = ConvertStringToLowercase(input);
		cout << "\n";
		if (input == "q")
			break;
		else
			HandleAction(theRandomWriter, input);
		cout << "\n";
	}
}

void HandleAction(RandomWriter & rw, string choice) {
	/// TO DO:
	/// Add code for the other menu choices.
	/// Use input validation for any additional question you ask the user.
	/// (For instance, if they enter a filename, it shouldn't be blank.
	/// A k value must be >= 0, and a length must be greater than the current k value.)
	if (choice == "") {
		rw.GenerateRandomOutput();
	} else if (choice == "k") {
		int kchoice = 0;
		cout << "Enter the a k value: ";
		cin >> kchoice;
		cout << endl;
		cin.clear();
		cin.ignore(32768, '\n');
		if (kchoice >= 0) {
			rw.SetKValue(kchoice);
		} else {
			cout << "Invalid choice of K value." << endl;
		}
	} else if (choice == "l") {
		int Lchoice = 0;
		cout << "Enter a length: ";
		cin >> Lchoice;
		cout << endl;
		cin.clear();
		cin.ignore(32768, '\n');
		if (Lchoice > rw.GetKValue()) {
			rw.SetLength(Lchoice);
		} else {
			cout << "Invalid choice of length." << endl;
		}
	} else if (choice == "f") {
		cout << "Enter a filename: ";
		string filename;
		getline(cin, filename);
		cout << endl;
		if (filename == "") {
			cout << "Invalid choice of filename." << endl;
		} else {
			rw.SetFilename(filename);
		}
	} else {
		cout << "That is not a valid choice.\n";
	}
}

void Menu(int currentKvalue, int currentLvalue, string currentFilename) {
	/// This is ALREADY COMPLETE.
	/// (However, if you don't like the formatting, feel free to change it.)
	cout << "=============================\n";
	cout << "         Random Writer    \n";
	cout << "=============================\n";
	cout << " Current settings\n";
	cout << " ----------------\n";
	cout << "  K value: " << currentKvalue << endl;
	cout << "  Length: " << currentLvalue << endl;
	cout << "  Input file: "
			<< ((currentFilename == "") ? "[none]" : currentFilename) << endl;
	cout << "=============================\n";
	cout << "| (K) Set K value           |\n";
	cout << "| (L) Set length            |\n";
	cout << "| (F) Change input file     |\n";
	cout << "| (Q) Quit                  |\n";
	cout << "| (Enter) Generate text     |\n";
	cout << "=============================\n";
}
