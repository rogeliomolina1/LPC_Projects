//*****************
//Project Name: Average Grade Calculator
//Project Description: Program to calculate average grade
//Project Author: Molina, Rogelio
//Is this an extra credit Project:  No
//Date completed: 09/10/2015
//Operating system used: Windows
//IDE Used:  Eclipse
//*****************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
void clearcin(void);
int main() {
	srand(time(0));
	const int TOTAL_GRADES = 4;
	double grade1 = 0;
	double grade2 = 0;
	double grade3 = 0;
	double grade4 = rand() % 100;
	double avgGrade = 0;
	string ID;
	string firstName, lastName, fullName;
	char LetterGrade = 0;

	cout << "Welcome to my Average\nGrade Calculator\n" << endl; // Welcomes user

	//Student info

	while (true) {
		cout << "Please Enter Your Student ID (1-10 Characters)" << endl;
		getline(cin, ID);
		if (ID.length() <= 0 || ID.length() >= 10) {
			cout << "Invalid Input\n";
		} else {
			break;
		}
	}
	while (true) {
		cout << "Please Enter Your Last Name (1-20 Characters)" << endl;
		getline(cin, lastName);
		if (lastName.length() <= 0 || lastName.length() >= 20) {
			cout << "Invalid Input\n";
		} else {
			break;
		}
	}
	while (true) {
		cout << "Please Enter Your First Name (1-12 Characters)" << endl;
		getline(cin, firstName);
		if (firstName.length() <= 0 || firstName.length() >= 12) {
			cout << "Invalid Input\n";
		} else {
			break;
		}
	}

	//Input of grades

	cout << "Enter Your Grades" << endl; //Tells user what to do
	while (true) {
		cout << "Please Enter Your First Grade" << endl; //Asks for Grade 1
		cin >> grade1;
		clearcin();
		if (grade1 < 0 || grade1 > 100) {
			cout << "Invalid Input\n";
		} else {
			break;
		}
	}
	while (true) {
		cout << "Please Enter Your Second Grade" << endl; //Asks for Grade 2
		cin >> grade2;
		clearcin();
		if (grade2 < 0 || grade2 > 100) {
			cout << "Invalid Input\n";
		} else {
			break;
		}
	}
	while (true) {
		cout << "Please Enter Your Third Grade" << endl; //Asks for Grade 3
		cin >> grade3;
		clearcin();
		if (grade3 < 0 || grade3 > 100) {
			cout << "Invalid Input\n";
		} else {
			break;
		}
	}

	//Calculate average and assign letter grades

	avgGrade = (grade1 + grade2 + grade3 + grade4) / TOTAL_GRADES;
	if (avgGrade >= 90) {
		LetterGrade = 'A';
	} else if (avgGrade >= 80) {
		LetterGrade = 'B';
	} else if (avgGrade >= 70) {
		LetterGrade = 'C';
	} else if (avgGrade >= 60) {
		LetterGrade = 'D';
	} else {
		LetterGrade = 'F';
	}

	cout << "Grade 1: " << grade1 << endl;
	cout << "Grade 2: " << grade2 << endl;
	cout << "Grade 3: " << grade3 << endl;
	cout << "Your Average Grade is: " << avgGrade << endl;

	fullName = lastName + ", " + firstName;
	cout << endl;
	cout << "Student Grade Report" << endl;
	cout << "====================\n\n" << endl;
	cout << left << setw(12) << "Stu-ID:  " << setw(22) << left << "Name:"
			<< setw(8) << "Grade 1:" << setw(10) << "  Grade 2:" << setw(10)
			<< "  Grade 3:" << setw(10) << "  Grade 4:" << setw(12)
			<< "  Avg Grade:" << setw(12) << "  Letter Grade:" << endl;
	cout << left << setw(12) << "----------  " << setw(22) << left
			<< "--------------------  " << setw(8) << "--------" << setw(10)
			<< "  --------" << setw(10) << "  --------" << setw(10)
			<< "  --------" << setw(12) << "  ----------" << setw(15)
			<< "  -------------" << endl;
	cout << setprecision(2) << fixed;
	cout << setw(12) << ID << setw(22) << left << fullName << setw(8) << right
			<< grade1 << setw(10) << right << grade2 << setw(10) << right
			<< grade3 << setw(10) << right << grade4 << setw(12) << right
			<< avgGrade << setw(15) << right << LetterGrade << endl;
	cout << endl;
	cout << "End of Program \nHave a Nice Day";
	return 0;
}
void clearcin(void) {
	cin.clear();
	cin.ignore(32768, '\n');
} //clearcin

