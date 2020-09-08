//============================================================================
// Name        : Permutation.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/// HELPER
void PermuteHelper(string soFar, string remain) {
	char nextChar;
	/// BASE CASE
	if (remain == "") {
		cout << soFar << endl;
	} else /// RECURSIVE STEP(S)
	{
		for (unsigned int i = 0; i < remain.length(); i++) {
			if (nextChar == remain[i]) {
				continue;
			} else {
				nextChar = remain[i];
				PermuteHelper(soFar + nextChar,
						remain.substr(0, i) + remain.substr(i + 1));
			}
		}
	}
}

/// WRAPPER
void Permute(string all) {
	PermuteHelper("", all);
}

int main() {
	string characters;
	cout << "Gimme a list of characters: ";
	getline(cin, characters);
	Permute(characters);
	return 0;
}
