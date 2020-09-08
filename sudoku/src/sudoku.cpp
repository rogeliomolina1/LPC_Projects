//============================================================================
// Name        : sudoku.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// Loads a 2-D array from the given file.
//  The function allocates memory for the array,
//  and also "returns" the width and height by setting
//  the two reference parameters
// NOTE: The returned array will have layer of 'X's around the
//  edge if the padding argument is true.
char **LoadArrayFromFile(string filename, int & w, int & h,
		bool padding = false);

// Displays a 4x4 array as a mini-Sudoku board
void DisplaySudoku(char **thearray);

// Determines if the given string consists
// of unique characters - that is, if each
// char in it occurs only once.
// Example: UniqueChars("bcda") will return true.
// Example: UniqueChars("acba") will return false.
bool UniqueChars(string s);

bool CheckBoard(char ** grid) {
	// TO DO: Implement this function so it checks
	// whether the current board state violates
	// any of the sudoku rules: So single row,
	// single column or single block of four
	// can have two of the same letter.
	for (int r = 0; r < 4; r++) {
		string rowstring = "";
		for (int c = 0; c < 4; c++) {
			if (grid[r][c] != '.') {
				rowstring += grid[r][c];
			}
		}
	}
	return true;
}

bool FindSolution(char **grid) {
	// TO DO: Implement this function.
	// When complete, it should do two things:
	// (1) Return true/false to indicate if the given
	//   sudoku grid is solvable.
	// (2) If it is solvable, set the grid to the final
	//   configuration.
	return false;
}

// DO NOT CHANGE THIS FUNCTION, OR ANY OTHER CODE BELOW

void SolveSudoku(string sudokufile) {
	int width, height;
	char **cells = LoadArrayFromFile(sudokufile, width, height);

	if (!cells) {
		cout << "File problem - giving up.\n";
		return;
	}
	if (width != 4 || height != 4) {
		cout << "Wrong dimensions (" << width << " x " << height
				<< ") - giving up.\n";
		return;
	}

	cout << "Initial Board:\n";
	DisplaySudoku(cells);
	cout << "\n";

	if (!FindSolution(cells))
		cout << "Not solvable!\n";
	else {
		cout << "Solution:\n";
		DisplaySudoku(cells);
	}
}

void DisplaySudoku(char **thearray) {
	string bar = " -- -- ";
	string margin = "    ";
	for (int r = 0; r < 4; r++) {
		if (!(r % 2))
			cout << margin << bar << "\n";
		cout << margin;
		for (int c = 0; c < 4; c++) {
			if (!(c % 2))
				cout << "|";
			cout << thearray[r][c];
		}
		cout << "|\n";
	}
	cout << margin << bar << "\n";
}

char **LoadArrayFromFile(string filename, int & width, int & height,
		bool padding) {
	ifstream infile(filename.c_str());

	width = 0;
	height = 0;

	string all;
	string line;

	int w, lastw;

	if (infile)
		getline(infile, line);
	else {
		cerr << "** Bad filename\n";
		return ((char **) 0);
	}

	w = line.length();
	lastw = w;
	all = line;

	while (infile) {
		getline(infile, line);
		if (line == "")
			break;
		w = line.length();
		if (w != lastw) {
			cerr << "** Bad file format - irregular widths " << w << " "
					<< lastw << "\n";
			return ((char **) 0);
		}
		all += line;
	}

	width = lastw;
	height = all.size() / width;

	int adj = 0;
	char ** grid;
	if (padding) {
		adj = 1;
		height += 2;
		width += 2;
	}
	grid = new char *[height];

	for (int r = 0; r < height; r++) {
		char * row = new char[width];
		if (padding) {
			row[0] = 'X';
			row[width - 1] = 'X';
		}
		for (int c = adj; c < width - adj; c++) {
			if (padding && (r == 0 || r == height - 1))
				row[c] = 'X';
			else {
				row[c] = all[(width - 2 * adj) * (r - adj) + (c - adj)];
			}
		}
		grid[r] = row;
	}

	return (grid);
}

bool UniqueChars(string s) {
	if (s.length() == 0)
		return true;
	sort(s.begin(), s.end());
	char last = s[0];
	for (unsigned int i = 1; i < s.length(); i++) {
		if (s[i] == last)
			return false;
		last = s[i];
	}
	return true;
}

int main() {

	SolveSudoku("board1.txt");
}

