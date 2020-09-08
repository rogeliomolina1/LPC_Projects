#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Creature {
protected:
	string name;
	int health;
public:
	Creature(string name);
	virtual void Describe() const=0;
};

class Mutant: public Creature {
protected:
	string power;
public:
	Mutant(string name, string power);
	void Describe() const;
	void UsePower() const;
};
class FlyingMutant: public Mutant {
protected:
	int flightSpeed;
public:
	FlyingMutant(string name);
	void Describe() const;
	void Fly() const;
};
class BuffMutant: public Mutant {
protected:
	int punchPower;
public:
	BuffMutant(string name);
	void Describe() const;
	void WorkOut() const;
};
Creature::Creature(string name) {
	this->name = name;
	this->health = 100;
}
Mutant::Mutant(string name, string power) :
		Creature(name) {
	this->health = 100;
	this->power = power;
}
void Mutant::Describe() const {
	cout << "Name: " << name << endl;
	cout << "Power: " << power << endl;
	cout << "Health: " << health << endl;
}
void Mutant::UsePower() const {
	cout << "arghhhh" << endl;
}
FlyingMutant::FlyingMutant(string name) :
		Mutant(name, "Flying") {
	this->health = 100;
	this->flightSpeed = 50;
}
void FlyingMutant::Describe() const {
	Mutant::Describe();
	cout << "Flight Speed: " << flightSpeed << "mph" << endl;
}
void FlyingMutant::Fly() const {
	cout << "Flap Flap Flap" << endl;
}
BuffMutant::BuffMutant(string name) :
		Mutant(name, "Strength") {
	this->health = 200;
	this->punchPower = 100;
}
void BuffMutant::Describe() const {
	Mutant::Describe();
	cout << "Punch Power: " << punchPower << " lbs" << endl;
}
void BuffMutant::WorkOut() const {
	cout << "Lift Lift Lift" << endl;
}
int main() {
	vector<Creature*> creatures;
	creatures.push_back(new Mutant("Bob", "Heat Vision"));
	creatures.push_back(new FlyingMutant("Joe"));
	creatures.push_back(new BuffMutant("Sam"));
	random_shuffle(creatures.begin(), creatures.end());
	for (unsigned int i = 0; i < creatures.size(); i++) {
		creatures[i]->Describe();
		Mutant*mutantPtr = dynamic_cast<Mutant*>(creatures[i]);
		if (mutantPtr != NULL)
			mutantPtr->UsePower();

		FlyingMutant*flyingmutantPtr = dynamic_cast<FlyingMutant*>(creatures[i]);
		if (flyingmutantPtr != NULL)
			flyingmutantPtr->Fly();

		BuffMutant*buffmutantPtr = dynamic_cast<BuffMutant*>(creatures[i]);
		if (buffmutantPtr != NULL)
			buffmutantPtr->WorkOut();

	}
	cout << endl;
	return 0;
}
