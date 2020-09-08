/*
 * Rectangle.cpp
 *
 *  Created on: Mar 10, 2016
 *      Author: rogel
 */

#include "Rectangle.h"

Rectangle::Rectangle(int width, int height, string color) :
		Shape("rectangle", color) {
	this->width = width;
	this->height = height;
}
string Rectangle::Description() const {
	stringstream ss;
	ss << width << "x" << height << " " << Shape::Description();
	return ss.str();
}
double Rectangle::Area() {
	return (width * height);
}
Rectangle::~Rectangle() {

}
