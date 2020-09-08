/*
 * SpellCheck.h
 *
 *  Created on: Sep 13, 2016
 *      Author: rogel
 */

#ifndef SPELLCHECK_H_
#define SPELLCHECK_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "lpclib.h"
#include "lexicon.h"
#include "scanner.h"
using namespace std;

string GetFile(string filename, bool &go);
void SpellCorrector(string filename, Lexicon * lex);
void Suggestions(string word, Lexicon * lex, ofstream &fout);
void TryReplacements(string word, Lexicon * lex, vector<string> &suggestions);
void TryAdditions(string word, Lexicon * lex, vector<string> &suggestions);
void TryDeletions(string word, Lexicon * lex, vector<string> &suggestions);
void Correct(vector<string> suggestions, string word, Lexicon*lex,
		ofstream &fout);

#endif /* SPELLCHECK_H_ */