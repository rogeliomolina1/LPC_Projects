/*
 * domino.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: rogel
 */

#include "domino.h"

Domino::Domino(int left, int right) {
	// TODO Auto-generated constructor stub
	LeftDots = left;
	RightDots = right;
}
string Domino::toString() {
	ostringstream ls;
	ostringstream rs;
	ls << LeftDots;
	rs << RightDots;
	SRep = (ls.str() + "|" + rs.str());
	return SRep;
}
int Domino::getLeftDots() const {
	return LeftDots;
}
int Domino::getRightDots() const {
	return RightDots;
}
void Domino::flip() {
	int temp;
	temp = LeftDots;
	LeftDots = RightDots;
	RightDots = temp;
}
