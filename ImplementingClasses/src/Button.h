/*
 * Button.h
 *
 *  Created on: Feb 2, 2016
 *      Author: student
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include <iostream>
using namespace std;
class Button {
private:
	int pressCount; // starts at 0
public:
	// CONSTRUCTOR
	Button();
	// MUTATOR
	void Press(); // increments the pressCount
	// ACCESSOR
	int TimesPressed() const; // returns the value of pressCount
};

#endif /* BUTTON_H_ */
