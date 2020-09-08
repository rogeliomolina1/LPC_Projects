/*
 * Location.h
 *
 *  Created on: Apr 21, 2016
 *      Author: rogel
 */

#ifndef LOCATION_H
#define LOCATION_H

#include "GameEntity.h"

class Location: public GameEntity {
protected:
	map<string, Location *> exits;
public:
	/// Constructor
	Location(string locName, string locDescription);

	/// Mutator to link a Location to an adjacent Location
	virtual void AddExit(string direction, Location * whereTo);

	/// Accessor to find a possible adjacent location
	virtual Location * FindExit(string direction) const;

	/// OVERRIDDEN method
	virtual void Describe();
};

#endif // LOCATION_H
