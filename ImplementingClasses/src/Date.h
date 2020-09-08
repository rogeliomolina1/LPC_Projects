/*
 * Date.h
 *
 *  Created on: Feb 2, 2016
 *      Author: student
 */

#ifndef DATE_H_
#define DATE_H_
#include <iostream>
#include <iomanip>
using namespace std;
class Date {
public:
	Date(int CYear, int CMonth, int CDay);
	void SetDate(int, int, int);
	void DisplayNumerically() const;
	void DisplayTextually()const;
private:
	int year;
	int month;
	int day;

};

#endif /* DATE_H_ */
