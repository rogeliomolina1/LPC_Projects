//============================================================================
// Name        : Warmup6.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Pizza.h"

int main() {
//Static allocation
	Pizza a(14);
	Pizza b("chicken", false, 16);
	a.AddTopping("bacon");
	b.AddTopping("onions");

	a.DescribePizza();
	b.DescribePizza();

	//Dynamic Allocation
	Pizza*p;
	Pizza*q;

	p = new Pizza(12);
	q = new Pizza("broccoli", true, 20);

	p->AddTopping("olives");
	p->AddTopping("mushrooms");
	p->AddTopping("artichoke hearts");
	p->DescribePizza();

	delete p;
	delete q;
	return 0;
}
