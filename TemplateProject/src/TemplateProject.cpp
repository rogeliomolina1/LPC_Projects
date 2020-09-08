//============================================================================
// Name        : TemplateProject.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

template<typename T>
T Pick(T x, T y, T z) {
	T Choice[3] = { x, y, z };
	int RandIndex = (rand() % 3);
	T Random = Choice[RandIndex];
	return Random;
}
template<typename T>
T GetChoice(string choiceOne, string choiceTwo, T x, T y) {
	string choice;
	while (choice != choiceOne && choice != choiceTwo) {
		cout << "Please pick " << choiceOne << " or " << choiceTwo << ": ";
		getline(cin, choice);
	}
	if (choice == choiceOne) {
		return x;
	} else {
		return y;
	}
}
template<typename T>
class UniqueList {
private:
	vector<T> items;
public:
	void Insert(T item);
	int Size() const;
	T GetFirst() const;
	T GetLast() const;
	T GetMax() const;
	T GetMin() const;
};
template<typename T>
void UniqueList<T>::Insert(T item) {
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i] == item) {
			cout << "No duplicates allowed!" << endl;
			return;
		}
	}
	items.push_back(item);
}
template<typename T>
int UniqueList<T>::Size() const {
	return (items.size());
}
template<typename T>
T UniqueList<T>::GetFirst() const {
	T FirstItem = items[0];
	return (FirstItem);
}
template<typename T>
T UniqueList<T>::GetLast() const {
	T LastItem = items.back();
	return (LastItem);
}
template<typename T>
T UniqueList<T>::GetMax() const {
	T MaxItem = items[0];
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i] >= MaxItem) {
			MaxItem = items[i];
		}
	}
	return (MaxItem);
}
template<typename T>
T UniqueList<T>::GetMin() const {
	T MinItem = items[0];
	for (unsigned int i = 0; i < items.size(); i++) {
		if (items[i] <= MinItem) {
			MinItem = items[i];
		}
	}
	return (MinItem);
}
int main() {
	srand(time(NULL));
	cout << Pick(4, 6, 7);
	cout << endl;
	cout << Pick(4, 6, 7);
	cout << endl;
	cout << Pick(4, 6, 7);
	cout << endl;
	cout << Pick(4, 6, 7);
	cout << endl;
	cout << Pick(4, 6, 7);
	cout << endl;
	cout << GetChoice("seven", "eleven", 7, 11);
	cout << endl;
	cout << GetChoice("eight", "twenty", 8, 20);
	cout << endl;
	cout << GetChoice("five", "eleven", 5, 11);
	cout << endl;
	cout << GetChoice("eleven", "three", 11, 3);
	cout << endl;
	UniqueList<string> words;
	UniqueList<int> favoriteNumbers;
	words.Insert("candy");
	words.Insert("cars");
	words.Insert("pizza");
	words.Insert("pineapple");
	words.Insert("pineapple");

	favoriteNumbers.Insert(55);
	favoriteNumbers.Insert(105);
	favoriteNumbers.Insert(300);
	favoriteNumbers.Insert(300);

	cout << words.GetFirst();
	cout << endl;
	cout << favoriteNumbers.GetFirst();
	cout << endl;
	cout << words.GetLast();
	cout << endl;
	cout << favoriteNumbers.GetLast();
	cout << endl;
	cout << words.GetMax();
	cout << endl;
	cout << favoriteNumbers.GetMax();
	cout << endl;
	cout << words.GetMin();
	cout << endl;
	cout << favoriteNumbers.GetMin();
	cout << endl;

	return 0;
}
