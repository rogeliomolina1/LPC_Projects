#include <iostream>

using namespace std;

class Vehicle {
protected:
	int weight;
	int wheels;
public:
	Vehicle(int weight, int wheels);
	void Describe() const;
};

Vehicle::Vehicle(int weight, int wheels) {
	this->weight = weight;
	this->wheels = wheels;
}

void Vehicle::Describe() const {
	cout << weight << " pounds, " << wheels << " wheels" << endl;
}

class Bicycle: public Vehicle {
protected:
	int averageSpeed;
public:
	Bicycle(int weight, int averageSpeed);
	void Describe() const;
};

Bicycle::Bicycle(int weight, int averageSpeed) :
		Vehicle(weight, 2) {
	this->averageSpeed = averageSpeed;
}

void Bicycle::Describe() const {
	Vehicle::Describe();
	cout << "Average speed: " << averageSpeed << " mph" << endl;
}

class DirtBike: public Bicycle {
protected:
	int engineSize;
public:
	DirtBike(int weight, int averageSpeed, int engineSize);
	void Describe() const;
};

DirtBike::DirtBike(int weight, int averageSpeed, int engineSize) :
		Bicycle(weight, averageSpeed) {
	this->engineSize = engineSize;
}

void DirtBike::Describe() const {
	Bicycle::Describe();
	cout << "Engine size: " << engineSize << " CCs" << endl;
}

int main() {
	Vehicle * v = new Vehicle(4000, 4);

	Bicycle * b = new Bicycle(12, 15);

	DirtBike * d = new DirtBike(500, 45, 450);

	v->Describe();

	cout << endl;

	b->Describe();

	cout << endl;

	d->Describe();
	return 0;
}
