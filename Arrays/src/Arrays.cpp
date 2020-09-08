//============================================================================
// Name        : Arrays.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void clearcin(void);
void printArray(double[], int);
int findLargestIntArray(int[], int);
int findSmallestIntArray(int[], int);
double findLargestIntArray(double[], int);
double findSmallestIntArray(double[], int);
float findLargestIntArray(float[], int);
float findSmallestIntArray(float[], int);
int main() {
	const int SIZE = 15;
	double tests[SIZE] = { 0 };
	int endOfArray = 0;
	int largestNumber, smallestNumber = 0;
	while (true) {
		printArray(tests, endOfArray);
		int tempInt = 0;
		cout
				<< "Please enter an integer value for the array (-999 to quit): \n";
		cin >> tempInt;
		clearcin();
		if (tempInt == -999)
			break;
		else {
			tests[endOfArray] = tempInt;
			endOfArray++;
		}
	}
	largestNumber = findLargestIntArray(tests, endOfArray);
	smallestNumber = findSmallestIntArray(tests, endOfArray);
	cout << "The largest and smallest values in the array were: "
			<< largestNumber << " and " << smallestNumber << endl;
	return 0;
}

void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
} //clearCin
void printArray(double anArray[], int theSize) {
	for (int ctr = 0; ctr < theSize; ctr++) {
		cout << ctr << ": " << anArray[ctr] << endl;
	} //for
} //clear array
int findLargestIntArray(int anArray[], int theSize) {
	int largestValue;
	largestValue = anArray[0];
	for (int i = 0; i < theSize; i++) {
		if (largestValue < anArray[i])
			largestValue = anArray[i];
		else
			continue;
	}
	return largestValue;
}
int findSmallestIntArray(int anArray[], int theSize) {
	int smallestValue;
	smallestValue = anArray[0];
	for (int i = 0; i < theSize; i++) {
		if (smallestValue > anArray[i])
			smallestValue = anArray[i];
		else
			continue;
	}
	return smallestValue;
}
double findLargestIntArray(double anArray[], int theSize) {
	int largestValue;
	largestValue = anArray[0];
	for (int i = 0; i < theSize; i++) {
		if (largestValue < anArray[i])
			largestValue = anArray[i];
		else
			continue;
	}
	return largestValue;
}
double findSmallestIntArray(double anArray[], int theSize) {
	int smallestValue;
	smallestValue = anArray[0];
	for (int i = 0; i < theSize; i++) {
		if (smallestValue > anArray[i])
			smallestValue = anArray[i];
		else
			continue;
	}
	return smallestValue;
}
float findLargestIntArray(float anArray[], int theSize) {
	int largestValue;
	largestValue = anArray[0];
	for (int i = 0; i < theSize; i++) {
		if (largestValue < anArray[i])
			largestValue = anArray[i];
		else
			continue;
	}
	return largestValue;
}
float findSmallestIntArray(float anArray[], int theSize) {
	int smallestValue;
	smallestValue = anArray[0];
	for (int i = 0; i < theSize; i++) {
		if (smallestValue > anArray[i])
			smallestValue = anArray[i];
		else
			continue;
	}
	return smallestValue;
}
