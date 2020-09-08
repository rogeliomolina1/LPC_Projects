/*
 * functions.cpp
 *
 *  Created on: Sep 4, 2016
 *      Author: rogel
 */

#include "function.h"

/////////////////////////////TASK # 1/////////////////////////////////////////////
void DrawBarGraph(GraphicsWindow * window, vector<double> values,
		bool separateBars, bool marksBetweenBars, int marksOnHorizontalAxis) {
	Color colorLine(255, 255, 255);
	Color colorBar(255, 0, 0);
	int MaxValue = 0;
	window->DrawLine(8, 8, 8, window->GetHeight() - 8, colorLine);
	window->DrawLine(8, window->GetHeight() - 8, window->GetWidth(),
			window->GetHeight() - 8, colorLine);
	for (unsigned int i = 0; i < values.size(); i++) {
		if (MaxValue < values[i]) {
			MaxValue = values[i];
		}
	}
	int pixelsPerUnit = (window->GetWidth() - 8) / MaxValue;
	if (!separateBars) {
		for (unsigned int i = 0; i < values.size(); i++) {
			int yAxis = 10 + (((window->GetHeight() - 20) / values.size()) * i);
			int barWidth = (window->GetHeight() - 20) / values.size();
			int barLength = values[i] * pixelsPerUnit;
			window->DrawRectangle(10, yAxis, barLength, barWidth, colorBar, 1);
			if (marksBetweenBars) {
				window->DrawLine(4, yAxis, 12, yAxis, colorLine);
			}
		}
	} else {
		for (unsigned int i = 0; i < values.size(); i++) {
			int yAxis = 10
					+ ((((window->GetHeight() - 20) / values.size())) * i);
			int barWidth = (window->GetHeight() - 60) / values.size();
			int barLength = values[i] * pixelsPerUnit;
			window->DrawRectangle(10, yAxis, barLength, barWidth, colorBar, 1);
			if (marksBetweenBars) {
				window->DrawLine(4, yAxis - 1, 12, yAxis - 1, colorLine);
			}
		}
	}
	for (int i = 0; i <= marksOnHorizontalAxis; i++) {
		if (marksOnHorizontalAxis > 0) {
			int space = (window->GetWidth() / marksOnHorizontalAxis);
			window->DrawLine(8 + (space * (i + 1)), window->GetHeight() - 4,
					(8 + space * (i + 1)), window->GetHeight() - 12, colorLine);
			window->DrawLine(window->GetWidth() - 1, window->GetHeight() - 4,
					window->GetWidth() - 1, window->GetHeight() - 12,
					colorLine);
		}
	}
	window->Refresh();
	window->WaitForMouseDown();
}

/////////////////////////////TASK # 2/////////////////////////////////////////////
void fixCounts(Grid<bool> & mines, Grid<int> & counts) {
	for (int i = 0; i < mines.numRows(); i++) {
		for (int j = 0; j < mines.numCols(); j++) {
			counts.setAt(i, j, countBools(mines, i, j));
		}
	}
}

int countBools(Grid<bool> bools, int row, int col) {
	int mineCount = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (bools.inBounds(i + row, j + col)) {
				if (bools.getAt(i + row, j + col)) {
					mineCount++;
				}
			}
		}
	}
	return mineCount;
}

void fillGrid(Grid<bool> &grid, vector<bool> &values) {
	int count = 0;
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			grid.setAt(i, j, values[count]);
			count++;
		}
	}
}

void printGrid(Grid<int> counts) {
	for (int i = 0; i < counts.numRows(); i++) {
		for (int j = 0; j < counts.numCols(); j++) {
			cout << counts.getAt(i, j) << " ";
		}
		cout << endl;

	}

}
/////////////////////////////TASK # 3/////////////////////////////////////////////
void SpellCheck(string text, Lexicon * lex) {
	Scanner scanner;
	string corrections;
	string tempWord;
	scanner.setInput(text);	scanner.setNumberOption(Scanner::ScanNumbersAsIntegers);
	cout << text;
	cout << endl;
	while (scanner.hasMoreTokens()) {
		tempWord = scanner.nextToken();
		if (lex->containsWord(tempWord) || tempWord == " "
				|| isupper(tempWord[0])) {
			for (unsigned int i = 0; i < tempWord.size(); i++) {
				corrections += " ";
			}
		} else {
			for (unsigned int i = 0; i < tempWord.size(); i++) {
				corrections += "-";
			}
		}

	}
	cout << corrections;
}
