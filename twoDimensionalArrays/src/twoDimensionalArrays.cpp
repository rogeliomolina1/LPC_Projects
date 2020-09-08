//*****************
//Project Name: Project #6
//Project Description: Uses parameters to main
//Project Author: Molina, Rogelio
//Is this an extra credit Project:  No
//Date completed: 10/27/2015
//Operating system used: Windows
//IDE Used:  Eclipse
//*****************

#include <iostream>
using namespace std;
const int COLS = 100;
const int ROWS = 100;
void clearcin(void);
double average(double anArray[][COLS], int, int, int);
int main() {
	double avgGrade = 0;
	int rowNumber = 0;
	double tempGrade = 0;
	int totalNames = 0;
	int totalGrades = 0;
	string names[ROWS];
	double grades[ROWS][COLS] = { 0 };
	cout << "Welcome to my grade input program\n";
	cout << "=================================\n";
	while (true) {
		cout << "How many student names would you like to enter (1-100)\n";
		cin >> totalNames;
		clearcin();
		if (totalNames <= 0 || totalNames > 100) {
			cout << "Invalid Input\n";
		} //if
		else {
			break;
		} //else
	} //while
	for (int i = 0; i < totalNames; i++) {
		cout << "Enter Name\n";
		getline(cin, names[i]);
		if (names[i] == "") {
			cout << "Invalid Input\n";
			i--;
		}
	}
	for (int ctr = 0; ctr < totalNames; ctr++) {
		cout << "Student #" << ctr + 1 << ": " << names[ctr] << endl;
	} //for
	while (true) {
		cout << "Choose number corresponding to student to enter grades\n";
		cin >> rowNumber;
		clearcin();
		if (rowNumber > 0 && rowNumber <= totalNames) {
			break;
		} else {
			cout << "Error, try again\n";
		}
	}
	for (int i = 0; i < COLS; i++) {
		cout << "Please enter grade " << i + 1 << " or -999 to exit\n";
		cin >> tempGrade;
		clearcin();
		if (tempGrade == -999) {
			totalGrades = i;
			for (int i = 0; i < totalGrades; i++) {
				cout << "Grade " << i + 1 << ": " << grades[rowNumber][i]
						<< endl;
			} //for
			avgGrade = average(grades, totalGrades, totalGrades, rowNumber);
			cout << "Average for all grades is " << avgGrade;
			break;
		} else if (tempGrade < 0 || tempGrade > 100) {
			cout << "Invalid Input\n";
			i--;
		} else {
			grades[rowNumber][i] = tempGrade;
		} //else
	}
	return 0;
}
void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
} //clearCin
double average(double anArray[][COLS], int total, int theSize, int rowNumber) {
	double average = 0;
	double sum = 0;
	for (int ctr = 0; ctr < (theSize + 1); ctr++) {
		sum = sum + anArray[rowNumber][ctr];
		average = (sum / total);
	} //for
	return average;
} //average
