//============================================================================
// Name        : ChangeMaker.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool ChangeHelper(vector<int> & sequence, int remaining,
		const vector<int> denominations) {
	/// (1) If the current state is a solution, SUCCESS!
	if (remaining == 0)
		return true;

	/// (2) Try each possible move from the current state....
	for (unsigned int i = 0; i < denominations.size(); i++) {
		int bill = denominations[i];
		if (bill <= remaining) {
			/// So this bill is a possible "move"
			/// (2b) Make that move, recursively ask if it leads to a solution
			remaining -= bill;
			sequence.push_back(bill);
			if (ChangeHelper(sequence, remaining, denominations) == true)
				return true;
			/// (2c) Unmake that move
			remaining += bill;
			sequence.pop_back();
		}
	}

	/// (3) We have achieved fail.
	return false;

}

bool CanMakeChange(int money, const vector<int> denominations) {
	vector<int> payback;
	bool result = ChangeHelper(payback, money, denominations);
	if (result == true) {
		for (unsigned int i = 0; i < payback.size(); i++) {
			cout << payback[i] << " ";
		}
		cout << endl;
	}
	return result;
}

int main() {
	vector<int> bills;
	bills.push_back(7);
	bills.push_back(5);
	while (true) {
		int amount;
		cout << "> ";
		cin >> amount;
		if (CanMakeChange(amount, bills))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}
