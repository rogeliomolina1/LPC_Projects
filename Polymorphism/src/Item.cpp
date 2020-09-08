/*
 * Item.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rogel
 */

#include "Item.h"
#include "Utility.h"

/// Constructor
Item::Item(string itemName, string itemDescription) {
	name = itemName;
	description = itemDescription;
}

/// Method: GetName
/// This is just an accessor.
/// Return this item's name.
string Item::GetName() const {
	return name;
}

/// Method: Describe
/// Print this item's description, using the
///      Utility::PrintWrappedString() method
void Item::Describe() const {
	Utility::PrintWrappedString(description);
}
