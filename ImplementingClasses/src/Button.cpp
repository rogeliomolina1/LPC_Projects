/*
 * Button.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: student
 */

#include "Button.h"

Button::Button() {
	// TODO Auto-generated constructor stub
	pressCount = 0;
}
void Button::Press() {
	pressCount++;
}

int Button::TimesPressed() const {
	return pressCount;
}

