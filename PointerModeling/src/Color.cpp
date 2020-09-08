/*
 * Color.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#include "Color.h"

Color::Color(double red, double green, double blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

string Color::Describe() const {
	stringstream ss;
	ss << "(" << red << ", " << green << ", " << blue << ")";
	return ss.str();
}
