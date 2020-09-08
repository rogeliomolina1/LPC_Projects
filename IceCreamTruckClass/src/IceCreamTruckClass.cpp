//============================================================================
// Name        : IceCreamTruckClass.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class IceCreamTruck {
private:
	map<string, int> sales;

public:
	/// CONSTRUCTOR
	IceCreamTruck(vector<string> flavorList);

	/// ACCESSORS
	void DisplayFlavors() const;
	void DisplaySalesReport() const;
	int NumSold(string flavor) const;
	bool HasFlavor(string flavor) const;

	/// MUTATORS
	void AddFlavor(string flavor);
	void Sell(string flavor, int scoops);
};

/// CONSTRUCTOR
IceCreamTruck::IceCreamTruck(vector<string> flavorList) {
	for (unsigned int i = 0; i < flavorList.size(); i++) {
		sales[flavorList[i]] = 0;
	}
}

/// ACCESSORS
void IceCreamTruck::DisplayFlavors() const {
	map<string, int>::const_iterator iter;
	for (iter = sales.begin(); iter != sales.end(); iter++) {
		cout << iter->first << endl;
	}
}

void IceCreamTruck::DisplaySalesReport() const {
	map<string, int>::const_iterator iter;
	for (iter = sales.begin(); iter != sales.end(); iter++) {
		cout << iter->first << ": " << iter->second << " scoops sold\n";
	}
}

int IceCreamTruck::NumSold(string flavor) const {
	if (HasFlavor(flavor))
		return sales.find(flavor)->second;
	else
		return 0;
}

bool IceCreamTruck::HasFlavor(string flavor) const {
	return (sales.find(flavor) != sales.end());
}

/// MUTATORS
void IceCreamTruck::AddFlavor(string flavor) {
	if (!HasFlavor(flavor))
		sales[flavor] = 0;
	else
		cout << "*** We already have " << flavor << "!\n";
}

void IceCreamTruck::Sell(string flavor, int scoops) {
	if (HasFlavor(flavor))
		sales[flavor] += scoops;
	else
		cout << "*** There is no " << flavor << " available to sell!" << endl;
}

int main() {
	vector<string> flavors;

	flavors.push_back("chocolate");
	flavors.push_back("vanilla");
	flavors.push_back("strawberry");

	IceCreamTruck truck(flavors);

	truck.AddFlavor("green tea");

	truck.Sell("green tea", 2);
	truck.Sell("vanilla", 1);
	truck.Sell("vanilla", 1);
	truck.Sell("strawberry", 17);

	truck.DisplayFlavors();

	cout << endl;

	truck.DisplaySalesReport();

}
