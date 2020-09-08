//============================================================================
// Name        : Input_OutputWithComments.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//create the stream
	ofstream fout;
	//use "open" to connect it to the file
	fout.open("menu.txt");
	//use the stream object to do output
	fout << "Fries $2" << endl;
	fout << "Cake $7" << endl;
	fout << "Salad $6" << endl;
	//close the stream object
	fout.close();
	cout << "Have a nice day!\n";
	//=========INPUT=========
	//create the stream
	ifstream fin;
	//user "open" to connect it to the file
	fin.open("document.txt");
	//check for failure
	if (fin.fail()) {
		cout << "Could not open!!" << endl;
		return -1;
	}
	//Use the stream object for input
	string line;
	getline(fin, line);

	cout << "The first line was: " << endl;
	cout << line << endl;
	//close the stream
	fin.close();
	return 0;
}
