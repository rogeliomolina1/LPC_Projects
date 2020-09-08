/*
 * Adventurer.h
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#ifndef ADVENTURER_H_
#define ADVENTURER_H_
#include <iostream>
using namespace std;
#include "Item.h"

class Adventurer {
private:
	string name;
	int level;
	string profession;
	Item * tool;

public:
	/// Constructor
	Adventurer(string n, int l, string p);

	/// Copy Constructor
	Adventurer(const Adventurer& otherObj);

	/// Mutator
	void GiveTool(string toolName, int toolPower, int toolDurability);

	/// Accessor
	void Describe() const;

	/// Destructor
	~Adventurer();
};

#endif /* ADVENTURER_H_ */
