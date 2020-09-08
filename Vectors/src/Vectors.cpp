//============================================================================
// Name        : Vectors.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include "utilities.hpp"
#include "student.hpp"

int main() {
	student myStudent;
	vector<student> myVectStu;
	bool keepGoing = true;
	while (keepGoing) {
		double tempGrade = 0;
		double avgGrade = 0;
		cout << "Welcome to Student Management System" << endl;
		cout << "====================================" << endl;
		myStudent.fname = enterString(
				"Please Enter the Student's First Name (1-12 Characters):", 0,
				12);
		myStudent.lname = enterString(
				"Please Enter the Student's Last Name (1-20 Characters):", 0,
				20);
		myStudent.stuID = enterInt("Please Enter the Student's ID (0-1000):", 0,
				1000);
		myStudent.age = enterDouble("Please enter Student Age (14-80):", 14,
				80);
		myStudent.major = enterString(
				"Please enter Student Major (max 4 characters):", 0, 4);

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
				<< myStudent.fname;
		cout << endl;
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
		myVectStu.push_back(myStudent);
		while (true) {
			cout << "Would you like to enter another student: " << endl
					<< "<Y>es or <N>o ==>";
			char answer;
			cin >> answer;
			clearcin();
			if (answer == 'y' || answer == 'Y') {
				break;
			} else if (answer == 'n' || answer == 'N') {
				cout << "\nYou have entered " << myVectStu.size()
						<< " students\n";
				for (unsigned int i = 0; i < myVectStu.size(); i++) {
					cout << "Student " << (i + 1) << ": " << endl;
					cout << "===========" << endl;
					cout << myVectStu[i].stuID << ": ";
					cout << myVectStu[i].lname << ", ";
					cout << myVectStu[i].fname;
					cout << endl;
					cout << "Age: ";
					cout << myVectStu[i].age << endl;
					cout << "Major: ";
					cout << myVectStu[i].major;
					cout << endl;

				}
				keepGoing = false;
				break;
			} else {
				cout << "Invalid Input";
				continue;
			}
		}

	}
	cout << "\nProgram Ending, have a great day!";
	return 0;
}
