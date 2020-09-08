//============================================================================
// Name        : SearchCS20.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
bool LinearSearch(vector<T> v, T target) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == target)
			return true;
	}
	return false;
}

template<typename T>
bool SortedLinearSearch(vector<T> v, T target) {
	/// ASSUMPTION: v is already sorted
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > target)
			return false; /// bail out early
		if (v[i] == target)
			return true;
	}
	return false;
}

template<typename T>
bool BinarySearch(vector<T> v, T target) {
	int start = 0;
	int finish = v.size() - 1;

	while (start <= finish) {
		int mid = (start + finish) / 2;

		if (v[mid] == target)
			return true;
		else if (target < v[mid])
			finish = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
