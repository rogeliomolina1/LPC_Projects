/*
 * Food.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: rogel
 */

#include "Food.h"
/// Constructor
Food::Food(string foodName, string foodDescription, string foodTaste) :
		Item(foodName, foodDescription) {
	taste = foodTaste;
}

/// Method: Eat
/// Print "You eat the ___, which tastes ___",
///  with the blanks filled in with the name and taste of this food.
void Food::Eat() const {
	cout << "You eat the " << name << ", which tastes " << taste << endl;
}
