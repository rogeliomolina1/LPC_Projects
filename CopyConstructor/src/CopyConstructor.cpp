//============================================================================
// Name        : CopyConstructor.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Adventurer.h"

int main() {
	/***
	 The lines below should run and give sensible output
	 once all of your code is working.
	 However, you should do YOUR OWN TESTING also.
	 ***/
	Adventurer a("Bob", 3, "baker");
	a.GiveTool("mixing bowl", 30, 20);
	a.Describe();
	a.GiveTool("spoon", 40, 10);
	a.Describe();

	Adventurer * p;
	p = new Adventurer("Mary", 4, "blacksmith");
	p->GiveTool("hammer", 100, 50);
	delete p;

	return 0;
}
