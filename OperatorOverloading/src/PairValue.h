/*
 * PairValue.h
 *
 *  Created on: Mar 8, 2016
 *      Author: rogel
 */

#ifndef PAIRVALUE_H_
#define PAIRVALUE_H_
#include <iostream>
#include <cmath>
using namespace std;

class PairValue {
private:
	double x;
	double y;
public:
	PairValue(double initialX, double initialY);
	friend class ostream;
	friend ostream& operator<<(ostream& os, PairValue obj);
	PairValue operator+(PairValue rightSide);
	PairValue operator-(PairValue rightSide);
	double operator*(PairValue rightSide);
	PairValue operator*(double rightSide);
	double operator%(PairValue rightSide);
	PairValue operator++();
	operator double();
};

#endif /* PAIRVALUE_H_ */
