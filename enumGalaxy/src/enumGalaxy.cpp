//============================================================================
// Name        : enumGalaxy.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

enum Drinks {
	WATER, COKEZERO, FATTYCOKE, ICEDTEA, MILK, PEPSI
};
//enum Drinks

enum MainCourses {
	PEPPERONIPIZZA,
	VEGGIEPIZZA,
	CHEESEPIZZA,
	STUFFEDCRUSTPIZZA,
	HEARTATTACKPIZZA
};
//enum MainCourses

enum Desserts {
	ICECREAM, CHOCOLATEPIZZA, CHEESECAKE, JELLO
};
//enum Desserts

struct lunchMenu {
	Drinks lunchDrink;
	MainCourses mainCourse;
	Desserts dessert;
};
//lunchMenu

string dessertToString(Desserts);
string mainToString(MainCourses);
string drinkToString(Drinks);
Drinks inputDrinks(void);
MainCourses inputMainCourse(void);
Desserts inputDessert(void);
int main() {
	lunchMenu myLunch;

	myLunch.lunchDrink = inputDrinks();

	myLunch.mainCourse = inputMainCourse();

	myLunch.dessert = inputDessert();

	cout << "You are ordering: " << drinkToString(myLunch.lunchDrink) << ", "
			<< mainToString(myLunch.mainCourse) << ", and "
			<< dessertToString(myLunch.dessert);
	return 0;
}

string dessertToString(Desserts aDessert) {
	string returnString;

	if (aDessert == ICECREAM) {
		returnString = "Ice Cream";
	}
	if (aDessert == CHOCOLATEPIZZA) {
		returnString = "Chocolate Pizza";
	}
	if (aDessert == CHEESECAKE) {
		returnString = "Cheesecake";
	}
	if (aDessert == JELLO) {
		returnString = "Jello";
	}
	return returnString;
}

string mainToString(MainCourses aMainCourse) {
	string returnString;

	if (aMainCourse == PEPPERONIPIZZA) {
		returnString = "Pepperoni Pizza";
	}
	if (aMainCourse == VEGGIEPIZZA) {
		returnString = "Veggie Pizza";
	}
	if (aMainCourse == CHEESEPIZZA) {
		returnString = "Cheese Pizza";
	}
	if (aMainCourse == STUFFEDCRUSTPIZZA) {
		returnString = "Stuffed Crust Pizza";
	}
	if (aMainCourse == HEARTATTACKPIZZA) {
		returnString = "Heart Attack Pizza";
	}
	return returnString;
}

string drinkToString(Drinks aDrink) {
	string returnString;

	if (aDrink == WATER) {
		returnString = "Water";
	}
	if (aDrink == COKEZERO) {
		returnString = "Coke Zero";
	}
	if (aDrink == FATTYCOKE) {
		returnString = "Fatty Coke";
	}
	if (aDrink == ICEDTEA) {
		returnString = "Iced Tea";
	}
	if (aDrink == MILK) {
		returnString = "Milk";
	}
	if (aDrink == PEPSI) {
		returnString = "Pepsi";
	}
	return returnString;
}

Drinks inputDrinks(void) {
	int userIntInput = 0;

	cout
			<< "0. Water\n1. Coke Zero\n2. Fatty Coke\n3. Iced Tea\n4. Milk\n5. Pepsi\n";
	cout << "Please enter what you want to drink at lunch: ";
	cin >> userIntInput;
	cin.clear();
	cin.ignore(32768, '\n');
	return static_cast<Drinks>(userIntInput);
}

MainCourses inputMainCourse(void) {
	int userIntInput = 0;

	cout
			<< "0. Pepperoni Pizza\n1. Veggie Pizza\n2. Cheese Pizza\n3. Stuffed Crust Pizza\n4. Heart Attack Pizza\n";
	cout << "Please enter what main course you want for lunch: ";
	cin >> userIntInput;
	cin.clear();
	cin.ignore(32768, '\n');
	return static_cast<MainCourses>(userIntInput);
}

Desserts inputDessert(void) {
	int userIntInput = 0;

	cout << "0. Ice Cream\n1. Chocolate Pizza\n2. Cheesecake\n3. Jello\n";
	cout << "Please enter what dessert you want for lunch: ";
	cin >> userIntInput;
	cin.clear();
	cin.ignore(32768, '\n');
	return static_cast<Desserts>(userIntInput);
}
