/*
 * student.hpp
 *
 *  Created on: Nov 3, 2015
 *      Author: student
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_
#include<iostream>
using namespace std;
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

#endif /* STUDENT_HPP_ */
