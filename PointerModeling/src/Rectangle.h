/*
 * Rectangle.h
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <sstream>
#include "Color.h"
using namespace std;
class Rectangle {
private:
	int width;
	int height;
	Color*fillColor;
public:
	Rectangle(int width, int height);    /// constructor
	Rectangle(const Rectangle& otherObj);    /// copy constructor
	string Description() const;
	void setFill(double r, double g, double b);
	~Rectangle();
};
#endif /* RECTANGLE_H_ */
