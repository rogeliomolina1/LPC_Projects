/*
 * Item.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#include "Item.h"

/// Constructor
Item::Item(string n, int p, int d) {
	name = n;
	power = p;
	durability = d;
}
/// Accessor
void Item::Describe() const {
	cout << name << " (power=" << power << ", durability=" << durability
			<< ")\n";
}
Item::~Item() {
	cout << "** Item " << name << " is being deallocated." << endl;
}
