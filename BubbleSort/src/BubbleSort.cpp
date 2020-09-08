//*****************
//Project Name: Project #5
//Project Description: Bubble Sorting
//Project Author: Molina, Rogelio
//Is this an extra credit Project:  No
//Date completed: 10/22/2015
//Operating system used: Windows
//IDE Used:  Eclipse
//*****************
#include <iostream>
using namespace std;
const int COLS = 100;
const int ROWS = 100;
void clearcin(void);
double average(double anArray[][COLS], int, int);
void bubbleSortArray(double array[][COLS], int, int);
void selectSortArray(double array[][COLS], int, int);
void printReport(double array[][COLS], int, int);
bool spaceCheck(string array[], int);
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
		cout << "\nEnter Name\n";
		getline(cin, names[i]);
		if (names[i] == "") {
			cout << "Invalid Input\n";
			i--;
		} else {
			bool keepGoing = true;
			keepGoing = spaceCheck(names, i);
			if (keepGoing) {
			} else {
				cout << "Invalid Input\n";
				i--;
			}
		} //else
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
			break;
		} else if (tempGrade < 0 || tempGrade > 100) {
			cout << "Invalid Input\n";
			i--;
		} else {
			grades[rowNumber][i] = tempGrade;
		} //else
	}
	//noSorting

	printReport(grades, totalGrades, rowNumber);
	avgGrade = average(grades, totalGrades, rowNumber);
	cout << "Average for all grades is " << avgGrade << endl << endl;

	//bubbleSort

	cout << "Sorting with Bubble Sort, ascending\n";
	bubbleSortArray(grades, totalGrades, rowNumber);
	printReport(grades, totalGrades, rowNumber);
	avgGrade = average(grades, totalGrades, rowNumber);
	cout << "Average for all grades is " << avgGrade << endl << endl;

	//selectSort

	cout << "Sorting with Select Sort, descending\n";
	selectSortArray(grades, totalGrades, rowNumber);
	printReport(grades, totalGrades, rowNumber);
	avgGrade = average(grades, totalGrades, rowNumber);
	cout << "Average for all grades is " << avgGrade << endl;
	cout << "\nProgram Ending\n";
	return 0;
}
void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
} //clearCin
double average(double anArray[][COLS], int theSize, int rowNumber) {
	double average = 0;
	double sum = 0;
	for (int ctr = 0; ctr < theSize; ctr++) {
		sum = sum + anArray[rowNumber][ctr];
		average = (sum / theSize);
	} //for
	return average;
} //average
void bubbleSortArray(double array[][COLS], int size, int rowNumber) {
	bool swap;
	int temp = 0;
	do {
		swap = false;
		for (int ctr = 0; ctr < (size - 1); ctr++) {
			if (array[rowNumber][ctr] > array[rowNumber][ctr + 1]) {
				temp = array[rowNumber][ctr];
				array[rowNumber][ctr] = array[rowNumber][ctr + 1];
				array[rowNumber][ctr + 1] = temp;
				swap = true;

			} //if
		} //for
	} while (swap);
} //bubbleSortArray
void selectSortArray(double array[][COLS], int size, int rowNumber) {
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = array[rowNumber][startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (array[rowNumber][index] > minValue) {
				minValue = array[rowNumber][index];
				minIndex = index;
			} //if
		} //for
		array[rowNumber][minIndex] = array[rowNumber][startScan];
		array[rowNumber][startScan] = minValue;
	} //for
} //selectSortArray
void printReport(double array[][COLS], int size, int rowNumber) {
	for (int i = 0; i < size; i++) {
		cout << "Grade" << i + 1 << ": " << array[rowNumber][i] << endl;
	} //for
}
bool spaceCheck(string array[], int rowNumber) {
	for (unsigned int ctr = 0; ctr < array[rowNumber].length(); ctr++) {
		if (array[rowNumber][ctr] == ' ') {
			return false;
		} //if
	} //for
	return true;
}
