//============================================================================
// Name        : 1.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Utility.h"
#include "GameException.h"
#include "GameEntity.h"
#include "Location.h"
#include <iostream>
using namespace std;

int main() {
	try {
		GameEntity cowbell("Cowbell",
				"A large cowbell, which once belonged to Will Farrell.");
		GameEntity Pizza("Pizza", "Pepperoni");
		cout << Pizza.GetName() << endl;
		cout << Pizza.GetDescription() << endl;
		Pizza.Add((new GameEntity("Hawaiian", "weird")));
		Pizza.Add((new GameEntity("Meat", "yum")));
		Pizza.ListContents();
		Pizza.Examine("Meat");
		Pizza.Remove("Meat");
		Pizza.Examine("Meat");
		Location Kitchen("Kitchen", "A place to cook");

		Location* LivingRoom = new Location("Living Room", "A place to relax");
		Kitchen.AddExit("north", LivingRoom);
		Location * KitchenExit = Kitchen.FindExit("north");
		cout << KitchenExit << endl;
		(*KitchenExit).Describe();

		Kitchen.Add(new GameEntity("Pan", "used to cook food"));
		Kitchen.Describe();
	} catch (GameException & e) {
		cout << "*** Internal Error: " << e.GetMessage() << endl;
	}
	return 0;
}

