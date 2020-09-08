/*
 * Location.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: rogel
 */

#include "Location.h"
#include "GameException.h"
#include "utility.h"
using namespace std;

Location::Location(string locName, string locDescription) :
		GameEntity(locName, locDescription) {
/// TO DO:
/// Implement the Locationconstructor
/// [Hint: The body of this method will remain empty]

}
void Location::AddExit(string direction, Location * whereTo) {
	/// TO DO:
	/// Add the given exit to the exits map.
	/// * HOWEVER, if the given direction already exists as a key in the map,
	///    throw a GameException with the message
	///    "Cannot add an second exit from ___ with direction ____"
	if (exits.find(direction) != exits.end()) {
		throw GameException(
				"Cannot add a second exit from " + name + " with direction "
						+ direction); // found
	} else {
		exits[direction] = whereTo;
	}
}

Location * Location::FindExit(string direction) const {
	/// TO DO:
	/// Check the exits map for an entry with the given direction as its key.
	/// If there is no such exit, return NULL.
	/// If there is, return the corresponding pointer-to-Location
	map<string, Location *>::const_iterator iter = exits.find(direction);
	if (iter != exits.end()) {
		return ((*iter).second);	// found
	} else {
		return NULL; /// THIS IS JUST A PLACEHOLDER
	}
}

void Location::Describe() {
	/// TO DO:
	/// (1) Print the location's name in *ALL CAPS*.
	/// (2) Print the location's description.
	/// (3) If there are any objects in the location's contents:
	///     a) Print "Here you can see __ things:"
	///     b) Call ListContents()
	cout << Utility::ConvertToUppercase(name) << endl;
	cout << description << endl;
	if (contents.size() != 0) {
		cout << "Here you can see " << contents.size() << " thing(s):" << endl;
		ListContents();
	}
}

