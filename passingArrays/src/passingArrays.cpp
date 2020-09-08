//============================================================================
// Name        : passingArrays.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
const int COLS = 8;
void getGrades(double[][COLS], int);

int main() {
	const int ROWS = 100;
	double grades[ROWS][COLS];
	getGrades(grades, ROWS);
	return 0;
}
void getGrades(double theArray[][COLS], int theSize) {
	int rowNumber = 0;
	int tempGrade = 0;
	while (true) {
		cout << "What row would you like to input grades into?" << endl;
		cin >> rowNumber;
		cin.clear();
		cin.ignore(32768, '\n');
		if (rowNumber >= 0 || rowNumber <= theSize) {
			break;
		} else
			cout << "Error, try again\n";
	}
	for (int i = 0; i < COLS; i++) {
		cout << "Please enter grade " << i << " or -999 to exit\n";
		cin >> tempGrade;
		cin.clear();
		cin.ignore(32768, '\n');
		if (tempGrade == -999) {
			break;
		} else {
			theArray[rowNumber][i] = tempGrade;
		}
	}
} //getGrades
