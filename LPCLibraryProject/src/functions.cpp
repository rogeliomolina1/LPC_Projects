/*
 * functions.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: rogel
 */
#include "functions.h"

/////////////////////TASK 1/////////////////////////
void AnagramHelper(string soFar, string currentWord, string remaining,
		unsigned int length, Lexicon*lex, vector<string>&found) {
	if (remaining == "") {
		/// soFar now contains a complete "answer"
		if (currentWord.length() >= length && lex->containsWord(currentWord)) {
			for (unsigned int j = 0; j < found.size(); j++) {
				if (found[j] == soFar) {
					return;
				}
			}
			cout << soFar << endl;
			found.push_back(soFar);
		}
	}
	for (unsigned int i = 0; i < remaining.length(); i++) {
		if (!lex->containsPrefix(currentWord)) {
			return;
		}
		if (lex->containsWord(currentWord) && currentWord.length() >= length) {
			AnagramHelper(soFar + " ", "", remaining, length, lex, found);
		}
		AnagramHelper(soFar + remaining[i], currentWord + remaining[i],
				remaining.substr(0, i) + remaining.substr(i + 1), length, lex,
				found);
	}
}

void Anagrams(string text, int minimumWordLength, Lexicon * lex) {
	vector<string> foundanagrams;
	for (unsigned int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') {
			text.erase(i, 1);
		}
	}
	AnagramHelper("", "", text, minimumWordLength, lex, foundanagrams);
}

////////////////////////////////////////////////////

/////////////////////TASK 2/////////////////////////
void MixHelper(string soFar, vector<string> flavors) {
	vector<string> temp;
	if (flavors.empty()) {
		cout << soFar << endl;
	} else {
		temp = flavors;
		temp.erase(temp.begin());
		MixHelper(soFar, temp);
		MixHelper(
				soFar
						+ ((!temp.empty() && soFar.size() == 0)
								|| soFar.size() == 0 ? "" : "-") + flavors[0],
				temp);
	}
}

void FlavorMixes(vector<string> flavors) {
	MixHelper("", flavors);
}
///////////////////////////////////////////////////////

///////////////////TASK 3///////////////////////////////
bool DominoHelper(vector<Domino> &soFar, vector<Domino> dominosAvailable) {
	if (dominosAvailable.empty()) {
		for (unsigned int i = 0; i < soFar.size(); i++) {
			soFar[i].Show();
		}
		return true;
	}
	for (unsigned int i = 0; i < dominosAvailable.size(); i++) {
		if (soFar.empty()) {
			soFar.push_back(dominosAvailable[i]);
			dominosAvailable.erase(dominosAvailable.begin() + i);
			if (DominoHelper(soFar, dominosAvailable) == true) {
				return true;
			} else {
				dominosAvailable.insert(dominosAvailable.begin() + i,
						soFar[soFar.size() - 1]);
				soFar.pop_back();
			}
		} else if (soFar[soFar.size() - 1].BottomNumber()
				== dominosAvailable[i].TopNumber()) {
			soFar.push_back(dominosAvailable[i]);
			dominosAvailable.erase(dominosAvailable.begin() + i);
			if (DominoHelper(soFar, dominosAvailable) == true) {
				return true;
			} else {
				dominosAvailable.insert(dominosAvailable.begin() + i,
						soFar[soFar.size() - 1]);
				soFar.pop_back();
			}
		} else if (soFar.size() == 1
				&& soFar[soFar.size() - 1].TopNumber()
						== dominosAvailable[i].TopNumber()) {
			soFar[0].Flip();
			soFar.push_back(dominosAvailable[i]);
			dominosAvailable.erase(dominosAvailable.begin() + i);
			if (DominoHelper(soFar, dominosAvailable) == true) {
				return true;
			} else {
				dominosAvailable.insert(dominosAvailable.begin() + i,
						soFar[soFar.size() - 1]);
				soFar.pop_back();
			}

		} else if (soFar[soFar.size() - 1].BottomNumber()
				== dominosAvailable[0].BottomNumber()) {
			dominosAvailable[0].Flip();
			soFar.push_back(dominosAvailable[0]);
			dominosAvailable.erase(dominosAvailable.begin() + i);
			if (DominoHelper(soFar, dominosAvailable) == true) {
				return true;
			} else {
				dominosAvailable.insert(dominosAvailable.begin() + i,
						soFar[soFar.size() - 1]);
				soFar.pop_back();
			}

		} else if (soFar.size() == 1
				&& soFar[soFar.size() - 1].TopNumber()
						== dominosAvailable[i].BottomNumber()) {
			dominosAvailable[i].Flip();
			soFar[0].Flip();
			soFar.push_back(dominosAvailable[i]);
			dominosAvailable.erase(dominosAvailable.begin() + i);
			if (DominoHelper(soFar, dominosAvailable) == true) {
				return true;
			} else {
				dominosAvailable.insert(dominosAvailable.begin() + i,
						soFar[soFar.size() - 1]);
				soFar.pop_back();
			}
		}
	}

	return false;
}

bool CanFormChain(vector<Domino> dominosAvailable) {
	vector<Domino> soFar;
	return (DominoHelper(soFar, dominosAvailable));
}
/////////////////////////////////////////////////////////////////////////
