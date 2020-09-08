//============================================================================
// Name        : Histogram.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int GetOneNumber(int minInput, int maxInput);

vector<int> GetInput(int minInput, int maxInput);

vector<int> GenerateCounts(const vector<int> & values);

void DisplayHistogram(const vector<int> & barCounts);

void PrintBar(int barLength);

int main() {
	DisplayHistogram(GenerateCounts(GetInput(0, 100)));
	return 0;
}

vector<int> GenerateCounts(const vector<int> & values) {
	vector<int> bins(11, 0);
	for (unsigned int i = 0; i < values.size(); i++) {
		bins[values[i] / 10]++;
	}
	return bins;
}

vector<int> GetInput(int minInput, int maxInput) {
	vector<int> result;
	while (true) {
		int value = GetOneNumber(minInput, maxInput);
		if (value == -1)
			break;
		result.push_back(value);
	}
	return result;
}

int GetOneNumber(int minInput, int maxInput) {
	int number = 0;
	while (true) {
		cout << "Enter a number from " << minInput << " to " << maxInput << ":";
		cin >> number;
		if (number == -1)
			return number;
		if (number >= minInput && number <= maxInput)
			return number;
		cout << "Invalid - try again.\n";
	}
}

void DisplayHistogram(const vector<int> & barCounts) {
	for (int binNumber = 0; binNumber < 11; binNumber++) {
		/// print label
		cout << binNumber << (binNumber == 10 ? "0" : "0s") << ": ";
		/// print bar
		PrintBar(barCounts[binNumber]);
	}
}

void PrintBar(int barLength) {
	for (int i = 0; i < barLength; i++)
		cout << "*";
	cout << endl;
}
