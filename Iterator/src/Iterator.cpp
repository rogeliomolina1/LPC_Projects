//============================================================================
// Name        : Iterator.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> colors;

	colors.push_back("red");
	colors.push_back("blue");
	colors.push_back("purple");
	colors.push_back("yellow");
	colors.push_back("green");
	colors.push_back("brown");
	colors.push_back("orange");
	colors.push_back("black");
	colors.push_back("white");
	colors.push_back("gray");
	colors.push_back("magenta");

	/***
	 /// Create an iterator that can be used
	 /// with a vector<string>
	 vector<string>::iterator iter;

	 /// "Put" the iterator at the beginning
	 /// position
	 iter = colors.begin();

	 /// Keep moving the iterator until it hits
	 /// the end position
	 while (iter != colors.end())
	 {
	 cout << (*iter) << endl;
	 iter++;  /// Move one space "forward"
	 }
	 ***/
	/// Here is a for-loop version of all of the above:
	for (vector<string>::iterator iter = colors.begin(); iter != colors.end();
			iter++) {
		cout << (*iter) << endl;
	}

	cout << endl;

	/// apply the built-in sort() function
	sort(colors.begin(), colors.end());

	for (vector<string>::iterator iter = colors.begin(); iter != colors.end();
			iter++) {
		cout << (*iter) << endl;
	}

	while (true) {
		string userColor;
		cout << "Enter a color: ";
		cin >> userColor;

		if (find(colors.begin(), colors.end(), userColor) == colors.end())
			cout << userColor << " is not in the vector." << endl;
		else
			cout << "Yup, found " << userColor << endl;
	}
	return 0;
}
