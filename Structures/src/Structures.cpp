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
string enterString(string, unsigned int, unsigned int);
double enterDouble(string, double, double);
int enterInt(string, int, int);
void clearcin(void);
double average(double anArray[], int);

const int MAXROWS = 100;

struct student {
	int stuID;
	string fname;
	string lname;
	string college;
	string major;
	double gpa;
	double age;
	double grades[MAXROWS];
	int totalGrades;
};
//student

int main() {
	student myStudent;
	double tempGrade = 0;
	double avgGrade = 0;
	cout << "Welcome to Student Management System" << endl;
	cout << "====================================" << endl;
	myStudent.fname = enterString(
			"Please Enter the Student's First Name (1-12 Characters):", 0, 12);
	myStudent.lname = enterString(
			"Please Enter the Student's Last Name (1-20 Characters):", 0, 20);
	myStudent.stuID = enterInt("Please Enter the Student's ID (0-999):", 0,
			999);
	myStudent.age = enterDouble("You want to enter Student Age:", 0, 99);
	myStudent.major = enterString("You want to enter Student Major:", 0, 4);

	for (int i = 0; i < MAXROWS; i++) {
		cout << "Please enter grade " << i + 1 << " (-999 to exit)\n";
		cin >> tempGrade;
		clearcin();
		if (tempGrade == -999) {
			myStudent.totalGrades = i;
			break;
		} else if (tempGrade < 0 || tempGrade > 100) {
			cout << "Invalid Input\n";
			i--;
		} else {
			myStudent.grades[i] = tempGrade;
		} //else
	}
	cout << "Student Details\n";
	cout << "---------------\n";
	cout << myStudent.stuID << ": " << myStudent.lname << ", "
			<< myStudent.fname << endl;
	cout << "Grades: ";
	for (int i = 0; i < myStudent.totalGrades; i++) {
		if (i == (myStudent.totalGrades - 1)) {
			cout << myStudent.grades[i] << endl;
		} else {
			cout << myStudent.grades[i] << ", ";
		}
	} //for
	avgGrade = average(myStudent.grades, myStudent.totalGrades);
	cout << "With an average grade of: " << avgGrade << endl;
	cout << "\nProgram Ending, have a great day!";
	return 0;
}
string enterString(string prompt, unsigned int min, unsigned int max) {
	bool keepGoing = true;
	string aString;
	while (keepGoing) {
		cout << prompt << endl;
		getline(cin, aString);
		if (aString.length() <= min || aString.length() > max) {
			cout << "Invalid Input\n";
		} else {
			keepGoing = false;
		} //else
	} //while
	return aString;
} //enterString
double enterDouble(string prompt, double min, double max) {
	double num = 0;
	while (true) {
		cout << prompt << endl;
		cin >> num;
		clearcin();
		if (num < min || num > max) {
			cout << "Invalid Input\n";
		} else {
			break;
		} //else
	} //while
	return num;
} //enterDouble
void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
} //clearCin
double average(double anArray[], int theSize) {
	double average = 0;
	double sum = 0;
	for (int ctr = 0; ctr < theSize; ctr++) {
		sum = sum + anArray[ctr];
		average = (sum / theSize);
	} //for
	return average;
} //average
int enterInt(string prompt, int min, int max) {
	int num = 0;
	while (true) {
		cout << prompt << endl;
		cin >> num;
		clearcin();
		if (num < min || num > max) {
			cout << "Invalid Input\n";
		} else {
			break;
		} //else
	} //while
	return num;
} //enterDouble
