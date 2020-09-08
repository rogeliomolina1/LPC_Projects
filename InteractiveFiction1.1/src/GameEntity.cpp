/*
 * GameEntity.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: rogel
 */

#include "GameEntity.h"
#include "GameException.h"
#include "Utility.h"
#include <iostream>
using namespace std;

GameEntity::GameEntity(string objName, string objDescription) {
	/// TO DO:
	/// Implement this constructor.
	/// * If the name is empty, it should throw an exception with the message
	///     "An game entity cannot have an empty name."
	/// * If the description is empty, it should throw an exception with the message
	///     "An game entity cannot have an empty description."
	if (objName == "") {
		throw GameException("An game entity cannot have an empty name.");
	} else {
		name = objName;
	}
	if (objDescription == "") {
		throw GameException("An game entity cannot have an empty description.");
	} else {
		description = objDescription;
	}
	enclosure = NULL;
}

/// TO DO: Implement the GetName method (return the current object's name)

/// TO DO: Implement the GetDescription method (return the current object's description)

/// TO DO: Implement the GetEnclosure method (return the current object's enclosure)
string GameEntity::GetName() const {
	return (name);
}
string GameEntity::GetDescription() const {
	return (description);
}
GameEntity * GameEntity::GetEnclosure() const {
	return (enclosure);
}

void GameEntity::ListContents() const {
	/// TO DO:
	/// Print the *name* of each object in the contents map, on separate lines.
	for (map<string, GameEntity *>::const_iterator iter = contents.begin();
			iter != contents.end(); iter++) {
		cout << (*iter).first << endl;
	}
}

GameEntity * GameEntity::FindInContents(string objName) {
	/// TO DO:
	/// Check whether the objName exists as a key in the contents map.
	/// * If it does exist, return the corresponding value.
	/// * If it does not exist, return NULL.
	if (contents.find(objName) != contents.end()) {
		return (contents[objName]); // found
	}
	return NULL; /// THIS IS JUST A PLACEHOLDER
}

void GameEntity::Add(GameEntity * obj) { /////////////////////////////Check//////////////////////////////////////////////
	/// TO DO:
	/// (1) Add the given value to the contents map.
	/// (2) Adjust the enclosure value of the given object appropriately.
	/// * HOWEVER, if the map already has an item with the same name,
	///    throw a GameException with the message
	///    "Attempt to insert a second ___ into ___"
	if (contents.find(obj->GetName()) != contents.end()) {
		throw GameException(
				"Attempt to insert a second " + obj->GetName() + " into "
						+ name);
	} else {
		contents[obj->GetName()] = obj;
		contents[obj->GetName()]->enclosure = this;
	}
}

bool GameEntity::Examine(string objName) {
	/// TO DO:
	/// (1) Search the contents map to see if an object with the given name exists.
	/// (2) If not, return false.
	/// (3) Otherwise, call the Describe() method of the object you found,
	///       then return true.
	/// [HINT: Use the FindInContents() method that you already wrote.]
	if (FindInContents(objName) != NULL) {
		contents[objName]->Describe(); // found
		return true;
	} else {
		return false;
	}
}

GameEntity * GameEntity::Remove(string objName) {
	/// TO DO:
	/// (1) Search the contents map to see if an object with the given name exists.
	/// (2) If not, return NULL.
	/// (3) Otherwise:
	///     a) remove the corresponding entry from the contents map
	///     b) set the enclosure of that object to NULL.
	/// [HINT: Use the FindInContents() method that you already wrote.]
	if (FindInContents(objName) != NULL) {
		contents[objName]->enclosure = NULL;
		contents.erase(objName);
	}
	return NULL;	/// THIS IS JUST A PLACEHOLDER
}

/// These are already implemented. DO NOT CHANGE THEM.

void GameEntity::Describe() {
	Utility::PrintWrappedString(description);
}

void GameEntity::Eat() {
	cout << "The " << name << " is not edible." << endl;
}

void GameEntity::Open() {
	cout << "The " << name << " is not something you can open." << endl;
}

void GameEntity::Close() {
	cout << "The " << name << " is not something you can close." << endl;
}

