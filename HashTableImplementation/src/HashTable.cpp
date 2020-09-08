/*
 * HashTable.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: rogel
 */

#include "HashTable.h"

int HashCode(string key);

const int INITIAL_SIZE = 7;

HashTable::HashTable() {
	tableSize = INITIAL_SIZE;
	table = new HashNode*[tableSize];
	numElements = 0;
	/// TO DO:
	/// Set all elements to NULL

	for (int i = 0; i < tableSize; i++) {
		table[i] = new HashNode;
		table[i]->data = "";
		table[i]->next = NULL;
	}
}

void HashTable::Insert(string key) {
	int code = HashCode(key) % tableSize;
	cout << "Key '" << key << "' hashes to " << code << endl;

	/// TO DO:
	/// Add a new node to the beginning of the linked list
	if (table[code]->data == "") {
		table[code]->data = key;
		numElements++;
	} else {
		HashNode* ptr = table[code];
		HashNode*n = new HashNode;
		n->data = key;
		n->next = ptr;
		table[code] = n;
		numElements++;
	}

	if (numElements > tableSize * 0.7) {
		/// TO DO:
		/// Reallocate a new, larger table
		/// Enter all elements into the new table
		int tempSize = tableSize;
		tableSize = tableSize + tableSize * 0.7;
		HashNode ** newTable = new HashNode*[tableSize];
		for (int j = 0; j < tableSize; j++) {
			newTable[j] = new HashNode;
			newTable[j]->data = "";
			newTable[j]->next = NULL;
		}
		for (int i = 0; i < tempSize; i++) {
			HashNode* current = table[i];
			if (current->data == "") {

			} else {
				while (current != NULL) {
					int code = HashCode(current->data) % tableSize;
					cout << "Key '" << current->data << "' hashes to " << code
							<< endl;
					if (newTable[code]->data == "") {
						newTable[code]->data = current->data;
					} else {
						HashNode* point = newTable[code];
						HashNode*o = new HashNode;
						o->data = current->data;
						o->next = point;
						newTable[code] = o;
					}
					current = current->next;
				}
			}
		}
		delete[] table;
		table = newTable;
	}

}

void HashTable::Remove(string key) {
	int code = HashCode(key) % tableSize;
	cout << "Trying to remove key '" << key << "' at index " << code << endl;

	/// TO DO:
	/// Search the linked list, and remove the match element

	HashNode* delptr;
	HashNode* ptr1;
	HashNode* ptr2;

	if (table[code]->data == "") {
		cout << key << " was not found in the Hash Table\n";
	} else if (table[code]->data == key && table[code]->next == NULL) {
		table[code]->data = "";
		cout << key << " was removed from the HashTable\n";
	} else if (table[code]->data == key) {
		delptr = table[code];
		table[code] = table[code]->next;
		delete delptr;
		cout << key << " was removed from the HashTable\n";
	} else {
		ptr1 = table[code]->next;
		ptr2 = table[code];
		while (ptr1 != NULL && ptr1->data != key) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		if (ptr1 == NULL) {
			cout << key << " was not found in the Hash Table\n";
		} else {
			delptr = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;
			delete delptr;
			cout << key << " was removed from the HashTable\n";
		}

	}

}

bool HashTable::Find(string key) {
	int code = HashCode(key) % tableSize;
	cout << "Looking for key '" << key << "' at index " << code << endl;

	/// TO DO:
	/// Search through the linked list

	HashNode* search = table[code];
	while (search != NULL) {
		if (search->data == key) {
			return true;
		}
		search = search->next;
	}
	return false;

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

