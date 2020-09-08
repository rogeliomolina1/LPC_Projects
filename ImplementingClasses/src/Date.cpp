/*
 * Date.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: student
 */

#include "Date.h"

Date::Date(int CYear, int CMonth, int CDay) {
	// TODO Auto-generated constructor stub
	if (CMonth > 12 || CMonth < 1 || CDay < 1) {
		cout << "Error: Date created with invalid date information.\n";
		year = 1900;
		month = 1;
		day = 1;
	} else if (CMonth == 2 && CDay > 28) {
		cout << "Error: Date created with invalid date information.\n";
		year = 1900;
		month = 1;
		day = 1;
	} else if (CMonth < 8 && CMonth % 2 != 0 && CDay > 31) {
		cout << "Error: Date created with invalid date information.\n";
		year = 1900;
		month = 1;
		day = 1;
	} else if (CMonth < 8 && CMonth % 2 == 0 && CDay > 30) {
		cout << "Error: Date created with invalid date information.\n";
		year = 1900;
		month = 1;
		day = 1;
	} else if (CMonth >= 8 && CMonth % 2 == 0 && CDay > 31) {
		cout << "Error: Date created with invalid date information.\n";
		year = 1900;
		month = 1;
		day = 1;
	} else if (CMonth >= 8 && CMonth % 2 != 0 && CDay > 30) {
		cout << "Error: Date created with invalid date information.\n";
		year = 1900;
		month = 1;
		day = 1;
	} else {
		year = CYear;
		month = CMonth;
		day = CDay;
	}

}
void Date::SetDate(int sYear, int sMonth, int sDay) {
	if (sMonth > 12 || sMonth < 1 || sDay < 1) {
		cout << "Error: SetDate() called with invalid date information.\n";

	} else if (sMonth == 2 && sDay > 28) {
		cout << "Error: SetDate() called with invalid date information.\n";

	} else if (sMonth < 8 && sMonth % 2 != 0 && sDay > 31) {
		cout << "Error: SetDate() called with invalid date information.\n";

	} else if (sMonth < 8 && sMonth % 2 == 0 && sDay > 30) {
		cout << "Error: SetDate() called with invalid date information.\n";

	} else if (sMonth >= 8 && sMonth % 2 == 0 && sDay > 31) {
		cout << "Error: SetDate() called with invalid date information.\n";

	} else if (sMonth >= 8 && sMonth % 2 != 0 && sDay > 30) {
		cout << "Error: SetDate() called with invalid date information.\n";

	} else {
		year = sYear;
		month = sMonth;
		day = sDay;
	}

}
void Date::DisplayNumerically() const {
	cout << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2)
			<< day << "/" << year << endl;
}
void Date::DisplayTextually() const {
	string monthName;
	if (month == 1)
		monthName = "January";
	else if (month == 2)
		monthName = "February";
	else if (month == 3)
		monthName = "March";
	else if (month == 4)
		monthName = "April";
	else if (month == 5)
		monthName = "May";
	else if (month == 6)
		monthName = "June";
	else if (month == 7)
		monthName = "July";
	else if (month == 8)
		monthName = "August";
	else if (month == 9)
		monthName = "September";
	else if (month == 10)
		monthName = "October";
	else if (month == 11)
		monthName = "November";
	else
		monthName = "December";
	cout << monthName << " " << day << ", " << year << endl;

}

