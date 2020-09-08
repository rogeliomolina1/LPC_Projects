//============================================================================
// Name        : SortingCS20.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void Show(vector<T> & v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

template<typename T>
void SelectionSort(vector<T> & v) {
	/// For every position from i up to N-2...
	for (int i = 0; i < v.size() - 1; i++)    /// N comparisons
			{
		/// scan from i up to N-1, find the smallest element
		T smallestItem = v[i];
		int smallestItemIndex = i;
		for (int k = i + 1; k < v.size(); k++) /// 1 + 2 + 3 + ... + (N-1) + 1
				{
			if (v[k] < smallestItem) {
				smallestItem = v[k];
				smallestItemIndex = k;
			}
		}
		/// Now I know where the smallest item is.
		/// So swap into position i
		swap(v[smallestItemIndex], v[i]);
	}
}

template<typename T>
vector<T> Merge(vector<T> vectorA, vector<T> vectorB) {
	int a = 0;
	int b = 0;

	vector<T> result;

	while (a < vectorA.size() && b < vectorB.size()) {
		if (vectorA[a] < vectorB[b]) {
			result.push_back(vectorA[a]);
			a++;
		} else {
			result.push_back(vectorB[b]);
			b++;
		}
	}

	while (a < vectorA.size()) {
		result.push_back(vectorA[a]);
		a++;
	}

	while (b < vectorB.size()) {
		result.push_back(vectorB[b]);
		b++;
	}

	return result;
}

template<typename T>
void MergeSort(vector<T> & v) {
	if (v.size() <= 1)
		return;

	vector<T> left;
	vector<T> right;

	for (int i = 0; i < v.size(); i++) {
		if (i < v.size() / 2) {
			left.push_back(v[i]);
		} else {
			right.push_back(v[i]);
		}
	}

	MergeSort(left);
	MergeSort(right);

	v = Merge(left, right);
}

template<typename T>
int Partition(vector<T> & v, int start, int finish) {
	T pivot = v[start];
	int left = start + 1;
	int right = finish;

	while (left <= right) {
		if (v[left] > pivot) {
			swap(v[left], v[right]);
			right--;
		} else {
			left++;
		}

	}
	swap(v[start], v[left - 1]);
	return (left - 1);
}

template<typename T>
void QuicksortHelper(vector<T>&v, int start, int finish) {
	if (start >= finish) {
		return;
	}
	int center = Partition(v, start, finish);
	QuicksortHelper(v, start, center - 1);
	QuicksortHelper(v, center + 1, finish);
}

template<typename T>
void Quicksort(vector<T>&v) {
	QuicksortHelper(v, 0, v.size() - 1);
}

int main() {

	vector<char> letters;

	letters.push_back('H');
	letters.push_back('N');
	letters.push_back('E');
	letters.push_back('P');
	letters.push_back('D');
	letters.push_back('F');
	letters.push_back('J');

	Quicksort(letters);

	Show(letters);

}
