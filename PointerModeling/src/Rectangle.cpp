/*
 * Rectangle.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#include "Rectangle.h"

Rectangle::Rectangle(int width, int height) {
	this->width = width;
	this->height = height;
	fillColor = NULL;
}

Rectangle::Rectangle(const Rectangle& otherObj) /// copy constructor
		{
	cout << "Kazaam! Making a copy of a Rectangle object." << endl;
	this->width = otherObj.width;
	this->height = otherObj.height;
	if (otherObj.fillColor == NULL) {
		this->fillColor = NULL;
	} else {
		this->fillColor = new Color(*(otherObj.fillColor));
	}
}

string Rectangle::Description() const {
	stringstream ss;
	ss << width << "x" << height << " rectangle";
	return ss.str();
}
void Rectangle::setFill(double r, double g, double b) {
	fillColor = new Color(r, g, b);
}
Rectangle::~Rectangle() {
	if (fillColor != NULL)
		delete fillColor;
}
