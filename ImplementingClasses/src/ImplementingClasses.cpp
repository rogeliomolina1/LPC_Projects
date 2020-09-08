//============================================================================
// Name        : ImplementingClasses.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Button.h"
#include "Date.h"

int main() {
	Button b;
	b.Press();
	b.Press();
	b.Press();
	cout << b.TimesPressed() << endl; /// prints "3"

	Date d(2015, 4, 12);
	d.DisplayNumerically(); /// prints "04/12/2015"
	d.DisplayTextually(); /// prints "April 12, 2015"

	Date e(2015, 8, 99); /// prints "Error: Date created with invalid date information."
	e.DisplayNumerically(); /// prints "01/01/1900"
	e.DisplayTextually(); /// prints "January 1, 1900"

	Date f(1980, 6, 8);
	f.DisplayNumerically(); /// prints "06/08/1980"
	f.DisplayTextually(); /// prints "June 8, 1980"

	f.SetDate(1980, 6, 31); /// prints "Error: SetDate() called with invalid date information"
	f.DisplayNumerically(); /// prints "06/08/1980"
	f.DisplayTextually(); /// prints "June 8, 1980"

	return 0;
}
