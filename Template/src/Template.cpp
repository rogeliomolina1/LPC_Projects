//============================================================================
// Name        : Template.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

//int Combine(int x, int y)
//{
//    int result = x + y;
//    return result;
//}
//
//string Combine(string x, string y)
//{
//    string result = x + y;
//    return result;
//}

/// Function TEMPLATE
template<typename T>
T Combine(T x, T y) {
	T result = x + y;
	return result;
}

int main() {
	string d = "dog";
	string h = "house";
	cout << Combine(7, 5) << endl;
	cout << Combine(d, h) << endl;
	return 0;
}
