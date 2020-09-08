//============================================================================
// Name        : maze.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/***

 This file contains functions that can be used to load and
 display a two-dimensional array of characters.

 ***/

/// Loads a 2-D array from the given file.
///  The function allocates memory for the array,
///  and also "returns" the width and height by setting
///  the two reference parameters
/// NOTE: The returned array will have layer of 'X's around the
///  edge if the 'padding' argument is true.
char **LoadArrayFromFile(string filename, int & w, int & h,
		bool padding = false);

/// Displays the given 2-D array on the console.
void DisplayArray(char **thearray, int w, int h);

bool SolveMaze(char ** maze, int currentRow, int currentCol, int goalRow,
		int goalCol);

int main() {
	/// This code demonstrates the use of the two functions.

	string fname;
	cout << "What filename? ";
	getline(cin, fname);

	int width;
	int height;
	char ** grid = LoadArrayFromFile(fname, width, height, true);

	cout << "The grid has been loaded. It's dimensions are " << width << " x "
			<< height << endl;

	DisplayArray(grid, width, height);
	int grow, gcol;
	cout << "What are the goal coordinates? ";
	cin >> grow;
	cin >> gcol;
	grid[1][1] = '@';

	if (SolveMaze(grid, 1, 1, grow, gcol)) {
		cout << "Solvable!" << endl;
		DisplayArray(grid, width, height);
	} else {
		cout << "NOT solvable." << endl;
	}

	return 0;
}
bool SolveMaze(char ** maze, int currentRow, int currentCol, int goalRow,
		int goalCol) {
//base case
	if (currentRow == goalRow && currentCol == goalCol)
		return true;

//For each available choice C...
	if (maze[currentRow - 1][currentCol] == ' ') {
//Make choice C
		maze[currentRow - 1][currentCol] = '@';
//Check: Is this solution possible from that point?
		if (SolveMaze(maze, currentRow - 1, currentCol, goalRow, goalCol)
				== true) {
			return true;
		} else {
			maze[currentRow - 1][currentCol] = ' ';
		}
//		(a) Yes: return true
//		(b) No: Unmake choice C
	}
	if (maze[currentRow + 1][currentCol] == ' ') {
		maze[currentRow + 1][currentCol] = '@';
		if (SolveMaze(maze, currentRow + 1, currentCol, goalRow, goalCol)
				== true) {
			return true;
		} else {
			maze[currentRow + 1][currentCol] = ' ';
		}
	}

	if (maze[currentRow][currentCol - 1] == ' ') {
		maze[currentRow][currentCol - 1] = '@';
		if (SolveMaze(maze, currentRow, currentCol - 1, goalRow, goalCol)
				== true) {
			return true;
		} else {
			maze[currentRow][currentCol - 1] = ' ';
		}
	}

	if (maze[currentRow][currentCol + 1] == ' ') {
		maze[currentRow][currentCol + 1] = '@';
		if (SolveMaze(maze, currentRow, currentCol + 1, goalRow, goalCol)
				== true) {
			return true;
		} else {
			maze[currentRow][currentCol + 1] = ' ';
		}
	}
	return false;
}

void DisplayArray(char **thearray, int w, int h) {
	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++)
			cout << thearray[r][c];
		cout << "\n";
	}
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

