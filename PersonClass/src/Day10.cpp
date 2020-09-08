//============================================================================
// Name        : Day10.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Person {
private:
	string fullname;
	int age;
	Person * father;
	Person * mother;
	vector<Person *> children;
public:
	/// CONSTRUCTORS
	Person(string fullname, int age);
	Person(const Person& otherPerson);
	/// GETTER
	string Description() const;
	/// SETTERS
	void SetAge(int age);
	void SetFullname(string fullname);
	void SetParents(Person * f, Person * m);
};

/// CONSTRUCTORS
Person::Person(string fullname, int age) {
	this->fullname = fullname;
	this->age = age;
	this->father = NULL;
	this->mother = NULL;
}

Person::Person(const Person& otherPerson) {
	this->fullname = otherPerson.fullname;
	this->age = otherPerson.age;
	this->SetParents(otherPerson.father, otherPerson.mother);
}
string Person::Description() const {
	stringstream ss;

	ss << fullname << "(age " << age << ")\n";
	ss << "   father: ";
	if (father == NULL)
		ss << "[unknown]\n";
	else
		ss << father->fullname << "\n";

	ss << "   mother: ";
	if (mother == NULL)
		ss << "[unknown]\n";
	else
		ss << mother->fullname << "\n";

	ss << "   children: ";
	if (children.size() == 0)
		ss << "NONE\n";
	else {
		ss << "\n";
		for (unsigned int i = 0; i < children.size(); i++)
			ss << "     " << children[i]->fullname << "\n";
	}
	return ss.str();
}

void Person::SetAge(int age) {
	this->age = age;
}

void Person::SetFullname(string fullname) {
	this->fullname = fullname;
}

void Person::SetParents(Person * f, Person * m) {
	this->father = f;
	this->mother = m;
	if (f != NULL)
		this->father->children.push_back(this);
	if (m != NULL)
		this->mother->children.push_back(this);
}

int main() {
	/// ===== Setting up people and links =====
	Person * mary = new Person("Mary", 55);
	Person * bob = new Person("Bob", 55);

	Person * joe = new Person("Joe", 35);
	joe->SetParents(bob, mary);

	/// "clone" joe's siblings
	Person * amy = new Person(*joe);
	amy->SetFullname("Amy");
	amy->SetAge(31);

	Person * kim = new Person(*joe);
	kim->SetFullname("Kim");
	kim->SetAge(28);

	Person * dan = new Person("Dan", 27);

	Person * mark = new Person("Mark", 1);

	mark->SetParents(dan, amy);

	/// ===== Setting up people and links =====

	cout << mary->Description() << endl;
	cout << bob->Description() << endl;
	cout << joe->Description() << endl;
	cout << amy->Description() << endl;
	cout << kim->Description() << endl;
	cout << dan->Description() << endl;
	cout << mark->Description() << endl;

	return 0;
}

