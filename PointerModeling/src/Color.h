/*
 * Color.h
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#ifndef COLOR_H_
#define COLOR_H_
#include <iostream>
#include <sstream>
using namespace std;
class Color {
private:
	double red;
	double green;
	double blue;
public:
	Color(double red, double green, double blue);
	string Describe() const;
};

#endif /* COLOR_H_ */
