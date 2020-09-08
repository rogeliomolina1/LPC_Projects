//============================================================================
// Name        : hanoi.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include<cstdlib>
using namespace std;
string blah;
// ====== The Towers class =======
// This class represents an entire Towers puzzle.
class Towers {
private:
	vector<int> posts[3];  // An array OF vectors!
	int numdiscs;

public:
	Towers(int N);  // Create a game with N discs
	void MoveDisc(char origin, char destination);
	void Display();
};

char OtherPost(char post1, char post2) {
	if (post1 != 'A' && post2 != 'A')
		return 'A';
	else if (post1 != 'B' && post2 != 'B')
		return 'B';
	else
		return 'C';
}
void MoveTower(Towers & t, int n, char from, char to) {
	if (n == 0)
		return;
	char intermediate = OtherPost(from, to);
	MoveTower(t, n - 1, from, intermediate);
	getline(cin, blah);
	t.MoveDisc(from, to);
	system("CLS");
	t.Display();
	MoveTower(t, n - 1, intermediate, to);
}

void SolveItAll(Towers & t, int n) {
	MoveTower(t, n, 'A', 'C');
}

int main() {
// Sample - initial setup for a game with N=5
	Towers game(10);
	game.Display();
	SolveItAll(game, 10);

}

// =============== Implementation details ================

// Code below here implements the Towers class. YOU SHOULD NOT
// CHANGE IT, and you do NOT NEED TO READ IT.

#define CHECK(expr, msg) if (!(expr)) { cout << "** FATAL ERROR: " << msg << endl; exit(-1); }

static void LineOf(char c, int n) {
	for (int i = 0; i < n; i++)
		cout << c;
}

Towers::Towers(int N) {
	for (int i = N; i >= 1; i--)
		posts[0].push_back(i);
	numdiscs = N;
}

void Towers::MoveDisc(char origin, char destination) {
	if (origin > 'Z')
		origin -= 32;
	if (destination > 'Z')
		destination -= 32;

	CHECK(destination >= 'A' && destination <= 'C',
			"Invalid post name " << destination);
	CHECK(origin >= 'A' && origin <= 'C', "Invalid post name " << origin);

	vector<int> & orig = posts[origin - 'A'];
	vector<int> & dest = posts[destination - 'A'];
	CHECK(orig.size() > 0,
			"Attempted to remove disc from empty tower " << origin);
	int disc = orig.back();
	CHECK(dest.empty() || disc < dest.back(),
			"Illegal move from " << origin << " to " << destination);
	orig.pop_back();
	dest.push_back(disc);
}

void Towers::Display() {
	int maxWidth = 2 * numdiscs - 1;
	int spacer = 3;

	cout << "\n";

	for (unsigned int level = numdiscs; level >= 1; level--) {
		for (int i = 0; i < 3; i++) {
			LineOf(' ', spacer);
			if (posts[i].size() < level)
				LineOf(' ', maxWidth);
			else {
				int width = 2 * posts[i][level - 1] - 1;
				LineOf(' ', (maxWidth - width) / 2);
				LineOf('*', width);
				LineOf(' ', (maxWidth - width) / 2);
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < 3; i++) {
		LineOf(' ', spacer);
		LineOf(' ', maxWidth / 2);
		cout << (char) ('A' + i);
		LineOf(' ', maxWidth / 2);
	}

	cout << "\n\n";

}
