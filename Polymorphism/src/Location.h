#ifndef LOCATION_H
#define LOCATION_H

#include "Item.h"
#include "Utility.h"
#include "Food.h"
class Location {
protected:

	/// These are the name and description of this location
	string name;
	string description;

	/// This is thelist of items in this location (possibly none)
	vector<Item *> contents;

public:
	/// Constructor
	Location(string locationName, string locationDescription);

	/// Method: GetName
	/// This is just an accessor.
	/// Return this location's name.
	string GetName() const;

	/// Method: Describe
	/// (1) Print the location's name in *ALL CAPS*.
	/// (2) Print The location's description, using the
	///      Utility::PrintWrappedString() method
	/// (3) If there are any objects in the location's contents:
	///     a) Print sentence "Here you can see __ things:" (__ is the number of items)
	///     b) Call ListContents()
	void Describe() const;

	/// Method: AddItem
	/// Add the given pointer to the end of the contents vector
	/// You can assume the pointer already points to a valid Item object.
	void AddItem(Item * itemPtr);

	/// Method: ExamineItem
	/// This has one parameter, representing the NAME of an item
	/// that may be in this location.
	/// It should respond one of two ways:
	/// (a) If there is no matching item, print "There is no ___ here.",
	///       with the ___ filled in with the parameter value.
	/// (b) If there is a matching item, call that item's Describe() method.
	void ExamineItem(string itemName) const;

	/// Method: EatFood
	/// This has one parameter, representing the NAME of an item
	/// that may be in this location.
	/// It should respond in one of three ways:
	/// (a) If there is no matching item, print "There is no ___ here."
	/// (b) If there is a matching item but it is not a Food,
	///       print "The ___ is not edible."
	/// (c) If there is a matching item and it is a Food,
	///       call that food's Eat() method,
	///       then ALSO deallocate that object
	///       and remove the corresponding entry from the vector.
	void EatFood(string itemName);

protected:
	/// Method: ListContents
	/// Loop through all contents (if any) of this location
	/// and print the name of each item.
	void ListContents() const;

};

#endif // LOCATION_H
