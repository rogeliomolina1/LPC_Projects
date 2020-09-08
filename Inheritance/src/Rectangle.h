/*
 * Rectangle.h
 *
 *  Created on: Mar 10, 2016
 *      Author: rogel
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"
class Rectangle: public Shape {
protected:
	int width;
	int height;
public:
	Rectangle(int width, int height, string color);
	string Description() const;
	double Area();
	~Rectangle();
};

#endif /* RECTANGLE_H_ */
