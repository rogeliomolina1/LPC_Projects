//============================================================================
// Name        : AlphabetizedList.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class AlphabetizedList {
private:
	vector<string> items;
public:
	AlphabetizedList& operator+=(string rightSide);
	AlphabetizedList operator+(AlphabetizedList rightSide);
	string operator~();
	string& operator[](int index);
};

AlphabetizedList& AlphabetizedList::operator+=(string rightSide) {
	items.push_back(rightSide);
	sort(items.begin(), items.end());
	return *this;
}
AlphabetizedList AlphabetizedList::operator+(AlphabetizedList rightSide) {
	AlphabetizedList result;
	result.items = this->items;
	for (unsigned int i = 0; i < rightSide.items.size(); i++) {
		result.items.push_back(result.items[i]);
	}
	sort(result.items.begin(), result.items.end());
	return result;
}
string AlphabetizedList::operator~() {
	stringstream ss;
	for (unsigned int i = 0; i < items.size(); i++) {
		ss << items[i] << endl;
	}
	return ss.str();
}
string& AlphabetizedList::operator[](int index) {
	return items[index];
}
int main() {
	AlphabetizedList players;
	(((players += "Bob") += "Mary") += "Alice") += "Kevin";

	string all = ~players;
	cout << all << endl;
	players += "Brenda";
	cout << ~players << endl;

	AlphabetizedList team2;

	team2 += "Joe";
	team2 += "Kim";

	cout << ~team2 << endl;

	AlphabetizedList team3 = team2 + players;
	cout << ~team3 << endl;

	cout << team3[0] << endl;
	cout << team3.operator[](0) << endl;
	team3[2] = "Zed";
	team3.operator[](2) = "Zed";

	cout << ~team3 << endl;

	return 0;
}
