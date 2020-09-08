#ifndef DOMINO_H
#define DOMINO_H
#include <iostream>
using namespace std;

/// This file defines the entire Domino class.
/// DO NOT alter it.

class Domino {
private:
	int topNum;
	int bottomNum;
public:
	Domino(int top = 0, int bottom = 0) :
			topNum(top), bottomNum(bottom) {
	}

	int TopNumber() const {
		return topNum;
	}
	int BottomNumber() const {
		return bottomNum;
	}
	void Show() const {
		cout << " ---\n";
		cout << "| " << topNum << " |\n";
		cout << "|- -|\n";
		cout << "| " << bottomNum << " |\n";
		cout << " ---\n";
	}
	void Flip() {
		int temp = bottomNum;
		bottomNum = topNum;
		topNum = temp;
	}
};

#endif
