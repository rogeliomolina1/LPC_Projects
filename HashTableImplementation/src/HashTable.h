/*
 * HashTable.h
 *
 *  Created on: Nov 30, 2016
 *      Author: rogel
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
using namespace std;

struct HashNode {
	string data;
	HashNode * next;
};

class HashTable {
private:
	HashNode ** table; /// dynamically allocated array of pointers to nodes
	int tableSize; /// should be a prime number
	int numElements;
public:
	HashTable();
	void Insert(string key);
	void Remove(string key);
	bool Find(string key);
};

#endif /* HASHTABLE_H_ */
