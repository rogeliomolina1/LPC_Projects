/*
 * Adventurer.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: student
 */

#include "Adventurer.h"

/// Constructor
Adventurer::Adventurer(string n, int l, string p) {
	/// TO DO: Implement this constructor
	name = n;
	level = l;
	profession = p;
	tool = NULL;
}

/// Copy Constructor
Adventurer::Adventurer(const Adventurer& otherObj) {
	/// TO DO: Initialize the current (new) object
	///  as an exact copy of otherObj.
	/// *** IF otherObj HAS AN ASSOCIATED TOOL, MAKE THE NEW OBJECT
	///        ALSO HAVE AN ASSOCIATED TOOL THAT DYNAMIALLY ALLOCATED
	///        AND EXACTLY MATCHES otherObj's TOOL
	this->name = otherObj.name;
	this->level = otherObj.level;
	this->profession = profession;
	/// DEEP COPY
	if (otherObj.tool == NULL)
		this->tool = NULL;
	else
		this->tool = new Item(*(otherObj.tool));
}

/// Mutator
void Adventurer::GiveTool(string toolName, int toolPower, int toolDurability) {
/// TO DO: Implement this method, following the specification
///         and the comments below.

/// if (this Adventurer does not already have a tool)
	if (tool == NULL) {
		/// Create a new, dynamically allocated Item object.
		/// Link to it with the tool variable.
		tool = new Item(toolName, toolPower, toolDurability);
	} else {
		cout << name << "'s existing tool is being replaced." << endl;
		/// First, DE-ALLOCATE the existing Item object linked through
		///  the tool variable.
		delete tool;
		/// THEN, create a new, dynamically allocated Item object,
		///  and link to it with the tool variable.
		tool = new Item(toolName, toolPower, toolDurability);
	}
}

/// Accessor
void Adventurer::Describe() const {
	cout << name << " is a level " << level << " " << profession << endl;

/// TO DO: Fill in the structure below so it behaves correctly.
/// if ( this Adventurer has a tool )
	if (tool != NULL) {
		cout << "His/her tool is: ";
		tool->Describe();

	} else {
		cout << "No tool\n";
	}
}

/// Destructor
Adventurer::~Adventurer() {
	cout << "Adventurer " << name << " is being deallocated.\n";
/// TO DO: Add code to correctly release any memory associated
///  with this object.
	{
		if (tool != NULL)
			delete tool;
	}

}
