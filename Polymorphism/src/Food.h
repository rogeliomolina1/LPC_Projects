#ifndef FOOD_H
#define FOOD_H
#include "Item.h"
#include <string>
using namespace std;

class Food: public Item {
protected:
	string taste;

public:
	/// Constructor
	Food(string foodName, string foodDescription, string foodTaste);

	/// Method: Eat
	/// Print "You eat the ___, which tastes ___",
	///  with the blanks filled in with the name and taste of this food.
	virtual void Eat() const;

};

#endif // FOOD_H
