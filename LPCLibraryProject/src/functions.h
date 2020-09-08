#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>
#include "domino.h"
#include "lexicon.h"
using namespace std;

void Anagrams(string text, int minimumWordLength, Lexicon * lex);
void FlavorMixes(vector<string> flavors);
bool CanFormChain(vector<Domino> dominosAvailable);

#endif //FUNCTIONS_H
