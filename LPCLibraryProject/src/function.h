/*
 * functions.h
 *
 *  Created on: Sep 4, 2016
 *      Author: rogel
 */
#include <iostream>
#include <vector>
#include "lpclib.h"
#include "grid.h"
#include "lexicon.h"
#include "scanner.h"

using namespace std;

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/////////////////////////////TASK # 1/////////////////////////////////////////////
void DrawBarGraph(GraphicsWindow * window, vector<double> values,
		bool separateBars = false, bool marksBetweenBars = true,
		int marksOnHorizontalAxis = 0);

/////////////////////////////TASK # 2/////////////////////////////////////////////
void fixCounts(Grid<bool> & mines, Grid<int> & counts);
int countBools(Grid<bool> bools, int row, int col);
void fillGrid(Grid<bool> &grid, vector<bool> &values);
void printGrid(Grid<int> counts);

/////////////////////////////TASK # 3/////////////////////////////////////////////
void SpellCheck(string text, Lexicon * lex);

#endif /* FUNCTIONS_H_ */
