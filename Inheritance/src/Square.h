/*
 * Square.h
 *
 *  Created on: Mar 10, 2016
 *      Author: rogel
 */

#ifndef SQUARE_H_
#define SQUARE_H_
#include "Rectangle.h"
class Square: public Rectangle {
public:
	Square(int sideLength, string color);
	string Description() const;
};

#endif /* SQUARE_H_ */
