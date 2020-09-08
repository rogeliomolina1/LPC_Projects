//============================================================================
// Name        : ExceptionHandling.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <fstream>
using namespace std;
bool IsDouble(string str);

class MenuItem {
private:
	string name;
	double price;
public:
	// Constructor - initialize the object from a given name and price
	MenuItem(string itemName, double itemPrice);

	// Constructor - initialize the object given a single text line
	//  using the syntax "itemname:price"
	MenuItem(string specification);

	// Print the name and price of this menu entry
	void Print();

	class InvalidItem {
	private:
		string message;
	public:
		InvalidItem(string message) {
			this->message = message;
		}
		string GetMessage() const {
			return message;
		}
	};
};

// Constructor - initialize the object from a given name and price
MenuItem::MenuItem(string itemName, double itemPrice) {
	if (itemName == "") {
		throw InvalidItem("blank name");
	}
	if (itemPrice <= 0) {
		throw InvalidItem("price must be positive");
	}
	name = itemName;
	price = itemPrice;
}

// Constructor - initialize the object given a single text line
//  using the syntax "itemname:price"
MenuItem::MenuItem(string specification) {
	unsigned int position = specification.find(":");
	if (position > specification.length()) {
		throw InvalidItem("must include a ':'");
	}
	name = specification.substr(0, position);
	if (name == "") {
		throw InvalidItem("blank name");
	}
	if (IsDouble(specification.substr(position + 1))) {
		char cPrice[100];
		strcpy(cPrice, specification.substr(position + 1).c_str());
		price = atof(cPrice);
	} else {
		throw InvalidItem("this is not a number");
	}
	MenuItem(name, price);
}

// Print the name and price of this menu entry
void MenuItem::Print() {
	cout << name << ": " << price << endl;
}

vector<MenuItem> GetMenuFromFile();

int main() {
	try {
		vector<MenuItem> menu = GetMenuFromFile();
		cout << "\nHere is the menu" << endl;
		for (unsigned int i = 0; i < menu.size(); i++) {
			menu[i].Print();
		}
	} catch (string& message) {
		cout << "Error: " << message << endl;
	} catch (MenuItem::InvalidItem& e) {
		cout << "Error: " << e.GetMessage() << endl;
	}
}

vector<MenuItem> GetMenuFromFile() {
	vector<MenuItem> result;

	string fileName;
	cout << "Give me the filename containing team data: ";
	getline(cin, fileName);

	/// 1) Create a stream
	ifstream fin;

	/// 2) Connect the stream using .open()
	fin.open(fileName.c_str());

	/// 2a) Check for failure
	if (fin.fail())
		throw string("Could not open file " + fileName);

	/// 3) Use the stream to get input
	int lineNumber = 1;
	do {
		string fileLine;
		getline(fin, fileLine);
		cout << "Reading line #" << lineNumber << endl;
		MenuItem temp(fileLine);
		result.push_back(temp);
		lineNumber++;
	} while (!fin.eof());

	/// 4) Close the file
	fin.close();

	return result;
}
bool IsDouble(string str) {
	int ctr = 0;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			ctr++;
			if (ctr > 1) {
				return false;
			}
		} else if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

