#pragma once
#include "mammal.h"

class Elephant : public Mammal {
private:
	string sound;

public:
	Elephant();
	Elephant(string n, string l, double w, int h);
	virtual ~Elephant() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Elephant::Elephant()
	: Mammal("New Elephant", "Location", 0.0, 0) {
	setSound("Pawoo!");
}
Elephant::Elephant(string n, string l, double w, int h)
	: Mammal(n, l, w, h) {
	setSound("Pawoo!");
}

void Elephant::setSound(string s) { sound = s; }
string Elephant::getSound() const { return sound; }

void Elephant::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Elephant::displayReport() const {
	Mammal::displayReport();
	cout 
		<< "Species: Elephant\n"
		<< "Sound: " << getSound() << endl;
}