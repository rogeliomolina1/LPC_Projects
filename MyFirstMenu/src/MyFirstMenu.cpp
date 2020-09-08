//*****************
//Project Name: Project #9
//Project Description: Final Project
//Project Author: Molina, Rogelio
//Is this an extra credit Project:  No
//Date completed: 12/9/2015
//Operating system used: Windows
//IDE Used:  Eclipse
//*****************

#include "utilities.hpp"
#include "student.hpp"
#include <iomanip>
#include <ctime>
#include <cstdlib>

int main() {
	student myStudent;
	cstudent myCStudent;
	vector<cstudent> myCVectStu;
	vector<student> myVectStu;
	char userChoice;
	char LetterGrade;
	unsigned int studentPosition = 0;
	fstream studentFile;
	char answer;
	//ofStream outputFile;
	do {
		cout << "Welcome to Student Management System" << endl;
		cout << "====================================" << endl;
		cout << " 1. Add a New Student\n";
		cout << " 2. Print Students\n";
		cout << " 3. Print Student Grades\n";
		cout << " 4. Clear Student Data\n";
		cout << " 5. Write Students to students.bin file\n";
		cout << " 6. Read Students from students.bin file\n";
		cout << " 7. Bubble Sort <Ascending> by Student ID\n";
		cout << " 8. Select Sort <Descending> by Student ID\n";
		cout << " 9. Exit Program\n";
		cout << "\nPlease Enter a Menu Option:\n";
		cin >> userChoice;
		clearcin();

		switch (userChoice) {
		case ('1'): {
			double tempGrade = 0;
			cout << "You want to enter a new student" << endl;
			cout << "===============================" << endl;
			myStudent.stuID = enterInt(
					"Please Enter the Student's ID (0-9999):", 0, 9999);
			myStudent.lname = enterString(
					"Please Enter the Student's Last Name (1-30 Characters):",
					0, 30);
			myStudent.fname = enterString(
					"Please Enter the Student's First Name (1-24 Characters):",
					0, 24);

			myStudent.age = enterDouble("Please enter Student Age (14-90):", 14,
					90);
			myStudent.major = inputMajor();
			myStudent.attendingCollege = inputCollege();

			for (int i = 0; i < MAXROWS; i++) {
				cout << "Please enter grade " << i + 1
						<< " (0-100 or -999 to exit)\n";
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

			myVectStu.push_back(myStudent);
			cout << endl << endl;
			break;
		} //case 1
		case ('2'): {
			string fullName;
			cout << "You want to print the Grade Report\n";
			cout << "==================================\n\n";
			cout << "Student Grade Report" << endl;
			cout << "====================\n\n";
			cout << setw(30) << right << "Name" << setw(12) << right << "ID"
					<< setw(9) << right << "College" << setw(7) << right
					<< "Major" << setw(12) << right << "Average" << setw(8)
					<< right << "Grade" << endl;
			cout << setw(32) << left << "==============================" << left
					<< setw(12) << "==========" << setw(9) << left << "======="
					<< setw(7) << left << "=====" << setw(12) << left
					<< "==========" << setw(8) << left << "======" << endl;
			if (myVectStu.size() == 0) {
				cout << "No students to print\n\n";
			}
			for (unsigned int i = 0; i < myVectStu.size(); i++) {
				if (average(myVectStu[i].grades, myVectStu[i].totalGrades)
						>= 90) {
					LetterGrade = 'A';
				} else if (average(myVectStu[i].grades,
						myVectStu[i].totalGrades) >= 80) {
					LetterGrade = 'B';
				} else if (average(myVectStu[i].grades,
						myVectStu[i].totalGrades) >= 70) {
					LetterGrade = 'C';
				} else if (average(myVectStu[i].grades,
						myVectStu[i].totalGrades) >= 60) {
					LetterGrade = 'D';
				} else {
					LetterGrade = 'F';
				} //Calculate average and assign letter grades
				fullName = myVectStu[i].lname + ", " + myVectStu[i].fname;
				cout << setw(30) << right << (fullName).substr(0, 30)
						<< setw(12) << right << myVectStu[i].stuID << setw(9)
						<< right
						<< collegeToString(myVectStu[i].attendingCollege)
						<< setw(7) << right << majorToString(myVectStu[i].major)
						<< setw(12) << right
						<< average(myVectStu[i].grades,
								myVectStu[i].totalGrades) << setw(8) << right
						<< LetterGrade;
				cout << endl;
			}
			cout << endl;
			break;
		} //case 2
		case ('3'): {
			if (myVectStu.size() == 0) {
				cout << "No students available\n\n";
			} else {
				while (true) {
					cout
							<< "Which student would you like to display grades for \n";
					printStudents(myVectStu);
					cout << "Enter one here: \n";
					cin >> studentPosition;
					clearcin();
					if (studentPosition < 0
							|| studentPosition > (myVectStu.size() - 1)) {
						cout << "Invalid Input\n";
					} else {
						printGrades(myVectStu, studentPosition);
						break;
					} //else
				} //while
			} //else
			break;
		} //case 3
		case ('4'): {
			cout << "Clearing Student Data\n";
			cout << "Are you sure?\n";
			while (true) {
				cout << "<Y>ES or <N>O ==>\n";
				cin >> answer;
				if (answer == 'y' || answer == 'Y') {
					myVectStu.clear();
					break;
				} else if (answer == 'n' || answer == 'N') {
					cout << "Not clearing data\n";
					break;
				} else {
					continue;
				}
			}
			break;
		} //case 4
		case ('5'): {
			cout << "You want to write student data to students.bin\n";
			studentFile.open("students.bin", ios::in | ios::binary);
			if (studentFile.fail()) {
				writeStudents(myVectStu, myCVectStu, studentFile, myCStudent);
			} else {
				studentFile.close();
				cout
						<< "File already exists. Would you like to overwrite the data?\n";
				while (true) {
					cout << "<Y>ES or <N>O ==>\n";
					cin >> answer;
					if (answer == 'y' || answer == 'Y') {
						writeStudents(myVectStu, myCVectStu, studentFile,
								myCStudent);
						break;
					} else if (answer == 'n' || answer == 'N') {
						cout << "Not overwriting data\n";
						break;
					} else {
						continue;
					}
				}
			}
			break;
		} //case 5
		case ('6'): {
			studentFile.open("students.bin", ios::in | ios::binary);
			if (studentFile.fail()) {
				cout << "File does not exist, try again later\n";
				break;
			} //if
			else {
				cout << "File exists, open successful\n";
				cout << "Reading data from students.bin\n";
				while (true) {
					studentFile.read(reinterpret_cast<char*>(&myCStudent),
							sizeof(cstudent));
					if (studentFile.eof()) {
						break;
					} else {
						int size = 0;
						size = myCStudent.totalGrades;
						myStudent.stuID = myCStudent.stuID;
						myStudent.lname = myCStudent.lname;
						myStudent.fname = myCStudent.fname;
						myStudent.age = myCStudent.age;
						myStudent.major = myCStudent.major;
						myStudent.attendingCollege =
								myCStudent.attendingCollege;
						myStudent.gpa = myCStudent.gpa;
						myStudent.totalGrades = myCStudent.totalGrades;
						for (int i = 0; i < size; i++) {
							myStudent.grades[i] = myCStudent.grades[i];
						}
						myVectStu.push_back(myStudent);
					}
				} //while
			}
			studentFile.close();
			break;
		} //case 6
		case ('7'):
			if (myVectStu.size() == 0) {
			} else {
				cout << "Sorting with Bubble Sort, ascending\n";
				bubbleSort(myVectStu);
			}
			break;
		case ('8'):
			if (myVectStu.size() == 0) {
			} else {
				cout << "Sorting with Select Sort, descending\n";
				selectSort(myVectStu, myVectStu.size());
			}
			break;
		case ('9'):
			break;
		default:
			cout << "Invalid menu option entered\n";
			break;
		} //switch
	} while (userChoice != '9');

	cout << "\nProgram is Ending\nGood Bye\n";
	return 0;
} //case 9

