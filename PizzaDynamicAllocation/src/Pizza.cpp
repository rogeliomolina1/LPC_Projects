/*
 * Pizza.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: student
 */

/*
 * Pizza.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: student
 */

#include "Pizza.h"

Pizza::Pizza(int howBig) {
	isThinCrust = true;
	numToppings = 1;
	toppings[0] = "cheese";
	diameter = howBig;

}

Pizza::Pizza(string topping, bool thin, int howBig) {
	numToppings = 1;
	toppings[0] = topping;
	isThinCrust = thin;
	diameter = howBig;

}

void Pizza::DescribePizza() const {
	string crust;
	if (isThinCrust)
		crust = "thin";
	else
		crust = "thick crust";
	cout << "This is a " << diameter << " inch " << crust
			<< " crust pizza with:\n";
	for (int i = 0; i < numToppings; i++) {
		cout << toppings[i] << "\n";
	}
}

int Pizza::GetNumToppings() const {
	return numToppings;
}

void Pizza::AddTopping(string topping) {
	if (numToppings >= MAX_TOPPINGS) {
		cout << "Max number of toppings reached\n";
	} else {
		toppings[numToppings] = topping;
		numToppings++;
	}
}

