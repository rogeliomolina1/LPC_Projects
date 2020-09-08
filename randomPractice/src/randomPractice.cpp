//#include<iostream>
//using namespace std;
//
//int Length(string str) {
//	if (str == "") {
//		return 0;
//	} else {
//		return 1 + Length(str.substr(1));
//	}
//}
//
//string Reverse(string str) {
//	if (str.length() <= 1) {
//		return str;
//	} else {
//		return (Reverse(str.substr(1)) + str[0]);
//	}
//}
//
//bool isPalindrome(string str) {
//	if (str.length() <= 1) {
//		return true;
//	} else if (str[0] != str[str.length() - 1]) {
//		return false;
//	} else {
//		if (isPalindrome(str.substr(1, str.length() - 1))) {
//			return true;
//		}
//	}
//}
//
//int main() {
//	cout << Length("pizza");
//	cout << endl << endl;
//	cout << Reverse("elephant");
//	return 0;
//}

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string Exp(int depth);
int RandInt(int min, int max);

int main() {

	int minDepth;
	int maxDepth;
	int depth;
	srand(time(0));
	while (true) {
		cout << "Enter a minimum depth (greater than or equal to 1):";
		cin >> minDepth;
		if (minDepth >= 1)
			break;
		else
			continue;
	}

	cout << "Enter a maximum depth:";
	cin >> maxDepth;
	depth = RandInt(minDepth, maxDepth);
	cout << Exp(depth) << endl;

}

string Exp(int depth) {
	if (depth == 1) {
		string var[2] = { "x", "y" };
		return var[rand() % 2];
	} else {
		int r = rand() % 4;
		switch (r) {
		case 0:
			return "sin(pi*" + Exp(depth - 1) + ")";
		case 1:
			return "cos(pi*" + Exp(depth - 1) + ")";
		case 2:
			return "avg(" + Exp(depth - 1) + "," + Exp(depth - 1) + ")";
		case 3:
			return Exp(depth - 1) + "*" + Exp(depth - 1);
		}
	}
	return "0";
}

int RandInt(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
