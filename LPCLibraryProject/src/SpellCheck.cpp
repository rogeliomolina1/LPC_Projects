/*
 * SpellChek.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: rogel
 */
#include "SpellCheck.h"

string GetFile(string filename, bool &go) {
	string text;
	ifstream infile(filename.c_str());
	if (!infile) {
		cout << "Could not open" << endl;
		go = false;
		return ("");
	}

	char c;
	infile.read(&c, 1);
	do {
		text += c;
		infile.read(&c, 1);
	} while (infile);
	go = true;
	return (text);
}

void SpellCorrector(string text, Lexicon * lex) {
	Scanner scanner;
	string tempWord;
	scanner.setInput(text);
	scanner.setNumberOption(Scanner::ScanNumbersAsIntegers);
	cout << endl;
	ofstream fout;
	fout.open("Revision.txt", ios::trunc);
	if (fout.fail()) {
		cout << "Could not open!!" << endl;
	}
	if (scanner.hasMoreTokens()) {
		tempWord = scanner.nextToken();
		if (lex->containsWord(tempWord) || tempWord == " ") {
			fout << tempWord;
		} else {
			cout << "'" << tempWord << "'" << " was not found.\n\n";
			Suggestions(tempWord, lex, fout);
		}
	}
	while (scanner.hasMoreTokens()) {
		tempWord = scanner.nextToken();
		if (tempWord == ".") {
			fout << tempWord;
			if (scanner.hasMoreTokens()) {
				tempWord = scanner.nextToken();
			} else {
				break;
			}
			if (tempWord == " ") {
				fout << tempWord;
				if (scanner.hasMoreTokens()) {
					tempWord = scanner.nextToken();
				} else {
					break;
				}
			}
		} else if (isupper(tempWord[0]) && tempWord != " ") {
			fout << tempWord;
			continue;
		}
		if (lex->containsWord(tempWord) || tempWord == " ") {
			fout << tempWord;
		} else {
			cout << "'" << tempWord << "'" << " was not found.\n\n";
			Suggestions(tempWord, lex, fout);
		}

	}
	fout.close();
}

void Suggestions(string word, Lexicon * lex, ofstream &fout) {
	vector<string> suggestions;
	/// Otherwise, print all words "close" to the given word
	TryReplacements(word, lex, suggestions);
	TryDeletions(word, lex, suggestions);
	TryAdditions(word, lex, suggestions);
	for (unsigned int i = 0; i < suggestions.size(); i++) {
		cout << i + 1 << ")" << suggestions[i] << endl;
	}
	Correct(suggestions, word, lex, fout);
}

void Correct(vector<string> suggestions, string word, Lexicon*lex,
		ofstream &fout) {
	string newWord;
	char choose;
	unsigned int chooseWord = 0;
	while (true) {
		cout << "What would you like to do:\n";
		cout << "a) Pick one of the suggestions\n";
		cout << "b) Enter a different spelling by hand\n";
		cout << "c) Mark the current word as correct\n";
		cin >> choose;
		if (toupper(choose) == 'A') {
			cout
					<< "Choose the number corresponding to the suggestion you would like to use:\n";
			for (unsigned int i = 0; i < suggestions.size(); i++) {
				cout << i + 1 << ")" << suggestions[i] << endl;
			}
			cin >> chooseWord;
			if (chooseWord <= suggestions.size() && chooseWord > 0) {
				fout << suggestions[chooseWord - 1];
				break;
			} else {
				cout << "That isn't one of the choices\n";
				continue;
			}
		} else if (toupper(choose) == 'B') {
			cout << "> ";
			cin >> newWord;
			cout << endl;
			fout << newWord;
			if (lex->containsWord(newWord)) {
			} else {
				lex->add(newWord);
			}
			break;
		} else if (toupper(choose) == 'C') {
			lex->add(word);
			fout << word;
			break;
		} else {
			continue;
		}
	}
}

void TryReplacements(string word, Lexicon * lex, vector<string> &suggestions) {
	for (unsigned int i = 0; i < word.size(); i++) {
		for (char letter = 'a'; letter <= 'z'; letter++) {
			string testWord = word;
			testWord[i] = letter;
			if (lex->containsWord(testWord)) {
				suggestions.push_back(testWord);
			}
		}
	}
}
void TryAdditions(string word, Lexicon * lex, vector<string> &suggestions) {
	for (unsigned int i = 0; i <= word.size(); i++) {
		for (char letter = 'a'; letter <= 'z'; letter++) {
			string testWord = word;
			string inserter = "";
			inserter += letter;
			testWord.insert(i, inserter);
			if (lex->containsWord(testWord)) {
				suggestions.push_back(testWord);
			}
		}
	}
}
void TryDeletions(string word, Lexicon * lex, vector<string> &suggestions) {
	for (unsigned int i = 0; i < word.size(); i++) {
		string testWord = word;
		testWord.erase(i, 1);
		if (lex->containsWord(testWord)) {
			suggestions.push_back(testWord);
		}
	}
}