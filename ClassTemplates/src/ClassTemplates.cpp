//============================================================================
// Name        : ClassTemplates.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

template<typename T>
class Box {
private:
	vector<T> items;
public:
	void Insert(T item);
	void Describe() const;
};

template<typename T>
void Box<T>::Insert(T item) {
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i] == item) {
			cout << "No duplicates allowed!" << endl;
			return;
		}
	}
	items.push_back(item);
}

template<typename T>
void Box<T>::Describe() const {
	cout << "This box has " << items.size() << " thing(s) in it:\n";
	for (unsigned int i = 0; i < items.size(); i++) {
		if (i == items.size() - 1)
			cout << " and ";
		else if (i > 0)
			cout << ", ";
		cout << items[i];
	}
	cout << endl;
}

int main() {
	Box<string> toys;
	Box<int> favoriteNumbers;

	toys.Insert("robot");
	toys.Insert("car");
	toys.Insert("yoyo");
	toys.Insert("robot");

	favoriteNumbers.Insert(17);
	favoriteNumbers.Insert(42);
	favoriteNumbers.Insert(23);

	toys.Describe();
	cout << endl;
	favoriteNumbers.Describe();
	return 0;
}
