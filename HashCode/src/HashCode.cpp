//============================================================================
// Name        : HashCode.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int HashCode(string key);

const int INITIAL_SIZE = 7;

class HashTable {
private:
	string * table; /// dynamically allocated array
	int tableSize; /// should be a prime number
public:
	HashTable();
	void Insert(string key);
	void Remove(string key);
	bool Find(string key);
};

HashTable::HashTable() {
	tableSize = INITIAL_SIZE;
	table = new string[tableSize];
}

void HashTable::Insert(string key) {
	int code = HashCode(key) % tableSize;
	cout << "Key '" << key << "' hashes to " << code << endl;
	if (table[code] == "")
		table[code] = key;
	else {
		cout << "Collision! Probing forward... " << endl;
		int index = code;
		while (true) {
			index = (index + 1) % tableSize;
			if (table[index] == "") {
				table[index] = key;
				cout << "Key '" << key << "' is actually at " << index << endl;
				break;
			}
		}
	}
}

void HashTable::Remove(string key) {
	int code = HashCode(key) % tableSize;
	cout << "Trying to remove key '" << key << "' at index " << code << endl;
	if (table[code] == key) {
		table[code] = "<USED>";
	}
	cout << "Failed to find at initial index, probing forward..." << endl;
	int index = code;
	while (true) {
		index = (index + 1) % tableSize;
		if (table[index] == key) {
			cout << "Removing at index " << index << " instead." << endl;
			table[index] = "<USED>";
		}
		if (table[index] == "") {
			return;
		}
	}

}

bool HashTable::Find(string key) {
	int code = HashCode(key) % tableSize;
	cout << "Looking for key '" << key << "' at index " << code << endl;
	if (table[code] == key)
		return true;
	cout << "Failed to find at initial index, probing forward..." << endl;
	int index = code;
	while (true) {
		index = (index + 1) % tableSize;
		if (table[index] == key) {
			cout << "Found at index " << index << endl;
			return true;
		}
		if (table[index] == "") {
			return false;
		}
	}

}

const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;

int HashCode(string str) {
	unsigned hash = HASH_SEED;
	int n = str.length();
	for (int i = 0; i < n; i++) {
		hash = HASH_MULTIPLIER * hash + str[i];
	}

	return int(hash & HASH_MASK);
}

int main() {
	HashTable animals;
	animals.Insert("cat");
	animals.Insert("fish");
	animals.Insert("elephant");

	cout << animals.Find("cat") << endl;
	cout << animals.Find("dog") << endl;
	cout << animals.Find("fish") << endl;
	cout << animals.Find("elephant") << endl;

}
