/*
 * Location.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rogel
 */

#include "Location.h"

/// Constructor
Location::Location(string locationName, string locationDescription) {
	name = locationName;
	description = locationDescription;
}
/// Method: GetName
/// This is just an accessor.
/// Return this location's name.
string Location::GetName() const {
	return name;
}
/// Method: Describe
/// (1) Print the location's name in *ALL CAPS*.
/// (2) Print The location's description, using the
///      Utility::PrintWrappedString() method
/// (3) If there are any objects in the location's contents:
///     a) Print sentence "Here you can see __ things:" (__ is the number of items)
///     b) Call ListContents()
void Location::Describe() const {
	cout << Utility::ConvertToUppercase(name) << endl;
	Utility::PrintWrappedString(description);
	if (!contents.empty()) {
		cout << "Here you can see " << contents.size() << " things: ";
		ListContents();
	}
}
/// Method: AddItem
/// Add the given pointer to the end of the contents vector
/// You can assume the pointer already points to a valid Item object.
void Location::AddItem(Item * itemPtr) {
	contents.push_back(itemPtr);
}
/// Method: ExamineItem
/// This has one parameter, representing the NAME of an item
/// that may be in this location.
/// It should respond one of two ways:
/// (a) If there is no matching item, print "There is no ___ here.",
///       with the ___ filled in with the parameter value.
/// (b) If there is a matching item, call that item's Describe() method.
void Location::ExamineItem(string itemName) const {
	for (unsigned int i = 0; i < contents.size(); i++) {
		if (contents[i]->GetName() == itemName) {
			contents[i]->Describe();
			break;
		} else if (i == contents.size() - 1) {
			cout << "There is no " << itemName << " here." << endl;
		}
	}
}
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
void Location::EatFood(string itemName) {
	for (unsigned int i = 0; i < contents.size(); i++) {
		if (contents[i]->GetName() == itemName) {
			Food * tempFoodPtr = dynamic_cast<Food *>(contents[i]);
			if (tempFoodPtr != NULL) {
				tempFoodPtr->Eat();
				delete contents[i];
				contents.erase(contents.begin() + (i));
				break;
			} else {
				cout << "The " << itemName << " is not edible" << endl;
				break;
			}
		} else if (i == contents.size() - 1) {
			cout << "There is no " << itemName << " here." << endl;
		}
	}
}
/// Method: ListContents
/// Loop through all contents (if any) of this location
/// and print the name of each item.
void Location::ListContents() const {
	if (!contents.empty()) {
		for (unsigned int i = 0; i < contents.size(); i++) {
			cout << contents[i]->GetName() << endl;
		}
	}
}
