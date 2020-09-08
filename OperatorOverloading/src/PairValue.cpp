/*
 * PairValue.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: rogel
 */

#include "PairValue.h"

ostream& operator<<(ostream& os, PairValue obj) {
	os << "(" << obj.x << ", " << obj.y << ")";
	return os;
}

PairValue::PairValue(double initialX, double initialY) {
	x = initialX;
	y = initialY;
}
PairValue PairValue::operator+(PairValue rightSide) {
	PairValue result(rightSide.x + this->x, rightSide.y + this->y);
	return result;
}
PairValue PairValue::operator-(PairValue rightSide) {
	PairValue result(this->x - rightSide.x, this->y - rightSide.y);
	return result;
}
double PairValue::operator*(PairValue rightSide) {
	double result((rightSide.x * this->x) + (rightSide.y * this->y));
	return result;
}
PairValue PairValue::operator*(double rightSide) {
	PairValue result(rightSide * this->x, rightSide * this->y);
	return result;
}
double PairValue::operator%(PairValue rightSide) {
	double distance;
	distance = sqrt(
			(this->x - rightSide.x) * (this->x - rightSide.x)
					+ (this->y - rightSide.y) * (this->y - rightSide.y));
	return distance;
}
PairValue PairValue::operator++() {
	double oldy = y;
	double oldx = x;
	this->x = -oldy;
	this->y = oldx;
	return *this;
}
PairValue::operator double() {
	return (x * y);
}
