#pragma once
#include "reptile.h"

class Alligator : public Reptile {
private:
	string sound;

public:
	Alligator();
	Alligator(string n, string l, double w, int h);
	virtual ~Alligator() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Alligator::Alligator()
	: Reptile("New Alligator", "Location", 0.0, 0) {
	setSound("Hiss!");
}
Alligator::Alligator(string n, string l, double w, int h)
	: Reptile(n, l, w, h) {
	setSound("Hiss!");
}

void Alligator::setSound(string s) { sound = s; }
string Alligator::getSound() const { return sound; }

void Alligator::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Alligator::displayReport() const {
	Reptile::displayReport();
	cout 
		<< "Species: Alligator\n"
		<< "Sound: " << getSound() << endl;
}