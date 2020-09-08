/*
 * Pizza.h
 *
 *  Created on: Feb 9, 2016
 *      Author: student
 */

/*
 * Pizza.h
 *
 *  Created on: Feb 9, 2016
 *      Author: student
 */

#ifndef PIZZA_H_
#define PIZZA_H_
#include <iostream>
using namespace std;

const int MAX_TOPPINGS = 10;
class Pizza {
private:
	string toppings[MAX_TOPPINGS];
	int numToppings;
	int diameter; // in inches
	bool isThinCrust;
public:
	/// CONSTRUCTORS

	/// Initialize a thin crust pizza with one topping, cheese,
	/// and the given size.
	Pizza(int howBig);

	/// Initialize a pizza with one topping as given
	/// and thin or thick crust as given.
	Pizza(string topping, bool thin, int howBig);

	// ACCESSORS

	/// Print a description of the pizza, including its size,
	/// whether it is thin or thick crust, and its list of
	/// toppings.
	void DescribePizza() const;

	/// Return the current number of toppings.
	int GetNumToppings() const;

	/// MUTATORS

	/// Add the given topping to the pizza, unless it has reached
	/// the maximum number of toppings, in which case print an error.
	void AddTopping(string topping);

};

#endif /* PIZZA_H_ */
