/*
 * Shape.cpp
 *
 *  Created on: Mar 10, 2016
 *      Author: rogel
 */

#include "Shape.h"

Shape::Shape(string name, string color) {
	this->name = name;
	this->color = color;
}
string Shape::Description() const {
	stringstream ss;
	ss << color << " " << name << endl;
	return ss.str();
}
Shape::~Shape() {

}
