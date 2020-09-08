/*
 * Square.cpp
 *
 *  Created on: Mar 10, 2016
 *      Author: rogel
 */

#include "Square.h"
Square::Square(int sideLength, string color) :
		Rectangle(sideLength, sideLength, color) {

}
string Square::Description() const {
	return (Rectangle::Description() + "(also known as a square)\n");
}
