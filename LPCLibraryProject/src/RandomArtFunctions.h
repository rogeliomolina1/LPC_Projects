/*
 * RandomArtFunctions.h
 *
 *  Created on: Sep 29, 2016
 *      Author: rogel
 */

#ifndef RANDOMARTFUNCTIONS_H_
#define RANDOMARTFUNCTIONS_H_3

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "expression.h"
#include "lpclib.h"
using namespace std;

string Exp(int depth);
int RandInt(int min, int max);
void RandomGreyscale(int depth, GraphicsWindow*w, Expression *E);
void RandomColor(int depth, GraphicsWindow*w);
void UserImage(string userExpression, GraphicsWindow*w);

#endif /* RANDOMARTFUNCTIONS_H_ */
