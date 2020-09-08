/*

 * student.hpp
 *
 *  Created on: Nov 12, 2015
 *      Author: student
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

enum college {
	LPC, SFO, BRK, SLU, WASHU, CSC
};

enum degreeMajor {
	CS, CIS, MTH, MUS, BUIS, VIT, PHY, ASTR, ENG
};

const int MAXROWS = 100;
struct student {
	int stuID;
	string fname;
	string lname;
	college attendingCollege;
	degreeMajor major;
	double gpa;
	double age;
	double grades[MAXROWS];
	int totalGrades;
};
//student

struct cstudent {
	int stuID;
	char fname[24];
	char lname[30];
	college attendingCollege;
	degreeMajor major;
	double gpa;
	double age;
	double grades[MAXROWS];
	int totalGrades;
};
//student

degreeMajor inputMajor(void) {
	int userIntInput = 0;
	while (true) {
		cout << "Enter one of these majors the student is working towards \n";
		cout
				<< "0. CS\n1. CIS\n2. MTH\n3. MUS\n4. BUIS\n5. VIT\n6. PHY\n7. ASTR\n8. ENG\n";
		cout << "Enter one here: \n";
		cin >> userIntInput;
		clearcin();
		if (userIntInput < 0 || userIntInput > 8) {
			cout << "Invalid Input\n";
		} else {
			break;
		} //else
	} //while
	return static_cast<degreeMajor>(userIntInput);
}
college inputCollege(void) {
	int userIntInput = 0;
	while (true) {
		cout << "Enter one of these colleges where the student is attending \n";
		cout << "0. LPC\n1. SFO\n2. BRK\n3. SLU\n4. WASHU\n5. CSC\n";
		cout << "Enter one here: \n";
		cin >> userIntInput;
		clearcin();
		if (userIntInput < 0 || userIntInput > 5) {
			cout << "Invalid Input\n";
		} else {
			break;
		} //else
	} //while
	return static_cast<college>(userIntInput);
}
string majorToString(degreeMajor aMajor) {
	string returnString;

	if (aMajor == CS) {
		returnString = "CS";
	}
	if (aMajor == CIS) {
		returnString = "CIS";
	}
	if (aMajor == MTH) {
		returnString = "MTH";
	}
	if (aMajor == MUS) {
		returnString = "MUS";
	}
	if (aMajor == BUIS) {
		returnString = "BUIS";
	}
	if (aMajor == VIT) {
		returnString = "VIT";
	}
	if (aMajor == PHY) {
		returnString = "PHY";
	}
	if (aMajor == ASTR) {
		returnString = "ASTR";
	}
	if (aMajor == ENG) {
		returnString = "ENG";
	}
	return returnString;
}
string collegeToString(college aCollege) {
	string returnString;

	if (aCollege == LPC) {
		returnString = "LPC";
	}
	if (aCollege == SFO) {
		returnString = "SFO";
	}
	if (aCollege == BRK) {
		returnString = "BRK";
	}
	if (aCollege == SLU) {
		returnString = "SLU";
	}
	if (aCollege == WASHU) {
		returnString = "WASHU";
	}
	if (aCollege == CSC) {
		returnString = "CSC";
	}
	return returnString;
}
void bubbleSort(vector<student>&theStudents) {
	bool swap;
	student temp;
	do {
		swap = false;
		for (unsigned int ctr = 0; ctr < (theStudents.size() - 1); ctr++) {
			if (theStudents[ctr].stuID > theStudents[ctr + 1].stuID) {
				temp = theStudents[ctr];
				theStudents[ctr] = theStudents[ctr + 1];
				theStudents[ctr + 1] = temp;
				swap = true;

			} //if
		} //for
	} while (swap);
} //bubbleSort
void selectSort(vector<student>&theStudents, unsigned int size) {
	unsigned int i, j;
	int min;
	student temp;
	for (i = 0; i < size - 1; i++) {
		min = i;   //setting min as i
		for (j = i + 1; j < size; j++) {
			if (theStudents[j].stuID > theStudents[min].stuID) //if element at j is less than element at min position
					{
				min = j;    //then set min as j
			}
		}
		temp = theStudents[i];
		theStudents[i] = theStudents[min];
		theStudents[min] = temp;
	}
} //selectSort
void printStudents(vector<student> theStudents) {
	for (unsigned int i = 0; i < theStudents.size(); i++) {
		cout << i << ": " << theStudents[i].lname << ", "
				<< theStudents[i].fname << endl;
	}
}

void printGrades(vector<student> theStudents, int whichStudent) {
	for (int i = 0; i < theStudents[whichStudent].totalGrades; i++) {
		cout << "grade #" << i << ": " << theStudents[whichStudent].grades[i]
				<< endl;
	}
}
void writeStudents(vector<student> &theStudents, vector<cstudent> &theCStudents,
		fstream &aFile, cstudent myCStudent) {
	aFile.open("students.bin", ios::out | ios::binary);
	if (aFile.fail()) {
		cout << "File open for output failed, program ending\n";
		return;
	} else {
		cout << "Writing student data to students.bin\n";
		for (unsigned int i = 0; i < theStudents.size(); i++) {
			strcpy(myCStudent.lname, theStudents[i].lname.c_str());
			strcpy(myCStudent.fname, theStudents[i].fname.c_str());
			myCStudent.stuID = theStudents[i].stuID;
			myCStudent.gpa = theStudents[i].gpa;
			myCStudent.totalGrades = theStudents[i].totalGrades;
			myCStudent.attendingCollege = theStudents[i].attendingCollege;
			myCStudent.major = theStudents[i].major;
			myCStudent.age = theStudents[i].age;
			for (int ctr = 0; ctr < myCStudent.totalGrades; ctr++) {
				myCStudent.grades[ctr] = theStudents[i].grades[ctr];
			}
			aFile.write(reinterpret_cast<char*>(&myCStudent), sizeof(cstudent));
		}
		aFile.close();
	}
}
#endif /* STUDENT_HPP_ */
