/*
 * Shape.h
 *
 *  Created on: Mar 10, 2016
 *      Author: rogel
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <sstream>
using namespace std;
class Shape {
protected:
	string name;
	string color;
public:
	Shape(string name, string color);
	string Description() const;
	~Shape();
};

#endif /* SHAPE_H_ */
