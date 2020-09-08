#include <iostream>
#include <vector>
using namespace std;

bool ConnectHelper(vector<string> & soFar, vector<string> & remain);

bool CanConnect(vector<string> wordList);

int main() {
	while (true) {
		vector<string> words;
		cout << "Enter words on separate lines, blank to end:" << endl;
		while (true) {
			string word;
			getline(cin, word);
			if (word == "")
				break;
			words.push_back(word);
		}
		bool connectable = CanConnect(words);

		if (!connectable)
			cout << "That set of words cannot be connected." << endl;

		cout << endl;
	}

}

bool ConnectHelper(vector<string> & soFar, vector<string> & remain) {
	if (remain.empty()) {
		return true;
	}
	for (unsigned int i = 0; i < remain.size(); i++) {
		/// Get current word...
		string currentWord = remain[i];
		/// Check if it is a possible move to add it to soFar
		if (soFar.empty()
				|| soFar.back()[soFar.back().length() - 1] == currentWord[0]) {
			/// Make the move
			soFar.push_back(currentWord);
			remain.erase(remain.begin() + i);
			/// Recursively see where that move leads
			if (ConnectHelper(soFar, remain) == true) {
				return true;
			}
			/// Unmake the move
			soFar.pop_back();
			remain.insert(remain.begin() + i, currentWord);
		}
	}
/// Getting here means no solution was found
	return false;
}

bool CanConnect(vector<string> wordList) {
	vector<string> sequence;
	bool result = ConnectHelper(sequence, wordList);
	if (result == true) {
		/// A solution was found - so show the sequence
		cout << "Solution: ";
		cout << sequence[0];
		for (unsigned int i = 1; i < sequence.size(); i++)
			cout << " -> " << sequence[i];
		cout << endl;
	}
	return result;
}
