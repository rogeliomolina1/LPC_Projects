//============================================================================
// Name        : Recursion_Vectors.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool ContainsE(string s);
/// returns true if s contains 'e' anywhere

int CountEs(string s);
/// returns the number of 'e' characters in s

bool Find(vector<string> items, string target);

int Count(vector<string> item, string target);

int main() {
	vector<string> stuff;
	stuff.push_back("cat");
	stuff.push_back("dog");
	stuff.push_back("emu");
	stuff.push_back("fish");
	stuff.push_back("goat");
	stuff.push_back("iguana");
	stuff.push_back("kangaroo");
	stuff.push_back("yak");
	cout << Find(stuff, "cat") << endl;
	cout << Find(stuff, "zebra") << endl;
}

bool FindHelper(vector<string> & v, int start, int stop, string target) {
	if (start > stop)
		return false;

	int mid = (start + stop) / 2;
	if (v[mid] == target)
		return true;

	if (target < v[mid])
		return FindHelper(v, start, mid - 1, target);  /// left half
	else
		return FindHelper(v, mid + 1, stop, target);  /// right half
}

bool Find(vector<string> items, string target) {
	return (FindHelper(items, 0, items.size() - 1, target));
}

int CountHelper(vector<string> & v, int start, int stop, string target) {
	if (start > stop)
		return 0;

	if (v[start] == target)
		return 1 + CountHelper(v, start + 1, stop, target);
	else
		return 0 + CountHelper(v, start + 1, stop, target);
}

int Count(vector<string> items, string target) {
	return (CountHelper(items, 0, items.size() - 1, target));
}

bool ContainsE(string s) {
	/// base case 1
	if (s == "")
		return false;
	/// base case 2
	if (s[0] == 'e')
		return true;

	/// recursive step
	return (ContainsE(s.substr(1)));
}

int CountEs(string s) {
	/// base case
	if (s == "")
		return 0;

	if (s[0] == 'e')
		return 1 + CountEs(s.substr(1));
	else
		return 0 + CountEs(s.substr(1));
}
