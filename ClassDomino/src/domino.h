/*
 * domino.h
 *
 *  Created on: Sep 19, 2016
 *      Author: rogel
 */

#ifndef DOMINO_H_
#define DOMINO_H_
#include <iostream>
#include <sstream>
using namespace std;

class Domino {
public:
	Domino(int left = 0, int right = 0);
	string toString();
	int getLeftDots() const;
	int getRightDots() const;
	void flip();
private:
	int LeftDots;
	int RightDots;
	string SRep;
};

#endif /* DOMINO_H_ */
