/*
 * Item.h
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
using namespace std;

class Item {
private:
	string name;
	int power;
	int durability;
public:
	/// Constructor
	Item(string n, int p, int d);
	/// Accessor
	void Describe() const;
	/// Destructor
	~Item();
};

#endif /* ITEM_H_ */
