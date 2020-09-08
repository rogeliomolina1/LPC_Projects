//#include <iostream>
//#include "lexicon.h"
//using namespace std;
//
//void SubsetHelper(string soFar, string remain) {
//	if (remain == "") {
//		cout << soFar << endl;
//	} else {
//		SubsetHelper(soFar, remain.substr(1));
//		SubsetHelper(soFar + remain[0], remain.substr(1));
//	}
//}
//
//void Subsets(string s) {
//	SubsetHelper("", s);
//}
//int main() {
//	Subsets("ABCD");
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include "lexicon.h"
//using namespace std;
//
//Lexicon lex("lexicon.dat");
//
//void ShowChain(vector<string> items) {
//	cout << items[0];
//	for (unsigned int i = 1; i < items.size(); i++) {
//		cout << " -> " << items[i];
//	}
//	cout << endl;
//}
//
//void ChainHelper(vector<string> & soFar, int remaining) {
//	/// cout << "remaining = " << remaining << endl;
//	/// base case
//	if (remaining == 0)
//		ShowChain(soFar);
//	else {
//		string currentWord = soFar.back();
//
//		for (unsigned int i = 0; i < currentWord.length(); i++) {
//			char currentLetter = currentWord[i];
//			/// cout << "Working on letter " << currentLetter << endl;
//			string newWord = currentWord;
//			for (char letter = 'a'; letter <= 'z'; letter++) {
//				if (letter != currentLetter) {
//					/// TRY ONE MOVE
//					/// (replace one letter in one position)
//					newWord[i] = letter;
//					/// cout << "Trying word " << newWord << endl;
//					if (lex.containsWord(newWord)
//							&& find(soFar.begin(), soFar.end(), newWord)
//									== soFar.end()) {
//						soFar.push_back(newWord);
//						/// Recursive call
//						ChainHelper(soFar, remaining - 1);
//						/// UNMAKE THAT MOVE
//						soFar.pop_back();
//					}
//				}
//			}
//		}
//	}
//}
//
//void FindChains(string startWord, int chainLength) {
//	vector<string> words;
//	words.push_back(startWord);
//	ChainHelper(words, chainLength);
//}
//
//int main() {
//	string userWord;
//	int userNum;
//	while (1) {
//		cout << "> ";
//		cin >> userWord >> userNum;
//		FindChains(userWord, userNum);
//	}
//}

#include "RandomArtFunctions.h"

int main() {
	srand(time(0));
	char userChoice = 0;
	char lastChoice = 0;
	int minDepth = 1;
	int maxDepth = 1;
	int length = 0;
	int height = 0;
	Expression *E;
	int depth = 0;
	while (true) {
		cout << "Please enter the length of the graphics window: ";
		cin >> length;
		cout << endl;
		cin.clear();
		cin.ignore(32768, '\n');
		if (length > 0) {
			break;
		} else {
			continue;
		}
	}
	while (true) {
		cout << "Please enter the height of the graphics window: ";
		cin >> height;
		cout << endl;
		cin.clear();
		cin.ignore(32768, '\n');
		if (height > 0) {
			break;
		} else {
			continue;
		}
	}

	GraphicsWindow w(length, height, "Random Artist");
	GraphicsWindow*ptr = &w;
	do {
		cout << endl << endl;
		cout << "Welcome to Random Art Generator" << endl;
		cout << "====================================" << endl;
		cout << " 1. Enter an expression\n";
		cout << " 2. Set the minimum and maximum recursion depth\n";
		cout << " 3. Generate a random greyscale image\n";
		cout << " 4. Generate for a random color image\n";
		cout << " 5. Quit\n";
		cout << "\nPlease Enter a Menu Option (1-5):\n";
		string choice;
		if (getline(cin, choice) && !choice.empty()) {
			userChoice = choice[0];
			lastChoice = userChoice;
		} else {
			userChoice = lastChoice;
		}

		switch (userChoice) {
		case ('1'): {
			string userExpression;
			cout << "Please enter a valid expression: ";
			cin >> userExpression;
			cin.clear();
			cin.ignore(32768, '\n');
			UserImage(userExpression, ptr);
			break;
		} //case 1
		case ('2'): {
			while (true) {
				cout << "Enter a minimum depth (greater than or equal to 1):";
				cin >> minDepth;
				cin.clear();
				cin.ignore(32768, '\n');
				if (minDepth >= 1)
					break;
				else
					continue;
			}
			while (true) {
				cout << "Enter a maximum depth:";
				cin >> maxDepth;
				cin.clear();
				cin.ignore(32768, '\n');
				if (maxDepth >= minDepth)
					break;
				else
					continue;
			}
			break;
		} //case 2
		case ('3'): {
			depth = RandInt(minDepth, maxDepth);
			RandomGreyscale(depth, ptr, E);
			break;
		} //case 3
		case ('4'): {
			depth = RandInt(minDepth, maxDepth);
			RandomColor(depth, ptr);
			break;
		} //case 4
		case ('5'):
			break;
		default:
			cout << "Invalid menu option entered\n";
			break;
		} //switch
	} while (userChoice != '5');

	cout << "\nProgram is Ending\nGood Bye\n";

}

//#include<iostream>
//#include "grid.h"
//#include "lpclib.h"
//using namespace std;
//
////int main() {
////	Grid<string> grid(8, 3);
////	grid.setAt(7, 2, "cat");
////
////}
//
///***
// MIDTERM REVIEW
//
// Format
// ------
// ~75%: short answer questions ON PAPER
// * write a sentence
// * read code, tell me what it will print
// * show procedures in action (sorts, recursive calls)
// * write 1-2 lines code
// ~25%: Write code with a compiler
// * Create actual functions/etc.
// Reference Sheet Provided!
// - names of methods in standard classes
// - names of methods in LPC library classes
//
// Topics
// ------
// * All of them
// * No exact counting of algorithm steps
// * Exactly 1 induction proof
//
//
//
// Schatz' Bullet Points
// ---------------------
// * Know your pointer syntax.
// &blah
// *blah
// foo * blah;
//
// * "new" does not mean new!
// "new ___" means "pointer to a new, dynamically allocated __"
//
// ***/
//
//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
///// 1) Stack is LIFO, Queue is FIFO
//
///// 9)
///***
//
// Selection Sort:
// 5 7 3 6 2 8 9
// 2 7 3 6 5 8 9
// 2 3 7 6 5 8 9
// 2 3 5 6 7 8 9
// 2 3 5 6 7 8 9
// 2 3 5 6 7 8 9
// 2 3 5 6 7 8 9
//
// Insertion Sort:
// 5 7 3 6 2 8 9
// 5 7 3 6 2 8 9
// 3 5 7 6 2 8 9
// 3 5 6 7 2 8 9
// 2 3 5 6 7 8 9
// 2 3 5 6 7 8 9
// 2 3 5 6 7 8 9
//
// Partition:
// 5|7 3 6 2 8 9|
// 5|9 3 6 2 8|7
// 5|8 3 6 2|9 7
// 5|2 3 6|8 9 7
// 5 2|3 6|8 9 7
// 5 2 3|6|8 9 7
// 5 2 3|6 8 9 7
// --------------
// 3 2 5|6 8 9 7
//
// Merge sort:
// [See picture]
//
//
// /// 10) [See picture]
//
// ***/
//
///// 6)
//string Reverse(string s) {
//	/// base case
//	if (s.length() <= 1) {
//		return s;
//	}
//	/// recursive step
//	return (Reverse(s.substr(1)) + s[0]);
//}
//
///// 7)
//int CountHelper(vector<string> v, int start, int finish, string target) {
//	/// base case
//	if (start > finish)
//		return 0;
//
//	/// recursive step
//	if (v[start] == target)
//		return 1 + CountHelper(v, start + 1, finish, target);
//	else
//		return 0 + CountHelper(v, start + 1, finish, target);
//}
//
//int CountMatches(vector<string> v, string target) {
//	return CountHelper(v, 0, v.size() - 1, target);
//}
//
///// 8)
//
//void SumHelper(vector<int> & soFar, int remain) {
//	/// base case - solution found!
//	if (remain == 0) {
//		for (int i = 0; i < soFar.size(); i++) {
//			cout << soFar[i] << " ";
//		}
//		cout << endl;
//	}
//
//	/// one possible move -- use a 1
//	if (remain >= 1) {
//		soFar.push_back(1);
//		remain -= 1;
//		SumHelper(soFar, remain);
//		remain += 1;
//		soFar.pop_back();
//	}
//
//	/// one possible move -- use a 3
//	if (remain >= 3) {
//		soFar.push_back(3);
//		remain -= 3;
//		SumHelper(soFar, remain);
//		remain += 3;
//		soFar.pop_back();
//	}
//
//}
//
//void PrintSums(int total) {
//	vector<int> sequence;
//	SumHelper(sequence, total);
//}
//
//int main() {
//
//	/// 2)
//	//Grid<string> grid(8, 3);
//	//grid.setAt(7, 2, "cat");
//
//	/// 3)
//	string * ptr;
//	ptr = new string;
//	*ptr = "fish";
//	delete ptr;
//
//	/// 4)
//	map<string, int> restaurants;
//	restaurants["Starbucks"] = 686780;
//	restaurants["In-N-Out"] = 123230;
//
//	if (restaurants.find("In-N-Out") == restaurants.end()) {
//		cout << "No, not found." << endl;
//	} else {
//		cout << "Customers served: " << restaurants["In-N-Out"] << endl;
//	}
//
//	/// 5)  [See picture]
//
//	/// 8)
//	PrintSums(12);
//}

//#include "lexicon.h"
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool FormWords(string startingWord, vector<char> letterList, Lexicon*lex);
//bool WordHelper(string startingWord, vector<char> letterList, Lexicon*lex,
//		vector<string> formed);
//int main() {
//	Lexicon lex("lexicon.dat");
//	Lexicon*ptr = &lex;
//	string startingWord = "air";
//	vector<char> letterList;
//	letterList.push_back('s');
//	letterList.push_back('h');
//	letterList.push_back('c');
//
//	FormWords(startingWord, letterList, ptr);
//	return 0;
//}

