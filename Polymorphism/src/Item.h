#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
	string name;
	string description;

public:
	/// Constructor
	Item(string itemName, string itemDescription);

	/// Method: GetName
	/// This is just an accessor.
	/// Return this item's name.
	string GetName() const;

	/// Method: Describe
	/// Print this item's description, using the
	///      Utility::PrintWrappedString() method
	virtual void Describe() const;

};

#endif // ITEM_H
