#pragma once
#include "mammal.h"

class Lion : public Mammal {
private:
	string sound;

public:
	Lion();
	Lion(string n, string l, double w, int h);
	virtual ~Lion() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Lion::Lion()
	: Mammal("New Lion", "Location", 0.0, 0) {
	setSound("Roar!");
}
Lion::Lion(string n, string l, double w, int h)
	: Mammal(n, l, w, h) {
	setSound("Roar!");
}

void Lion::setSound(string s) { sound = s; }
string Lion::getSound() const { return sound; }

void Lion::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Lion::displayReport() const {
	Mammal::displayReport();
	cout 
		<< "Species: Lion\n"
		<< "Sound: " << getSound() << endl;
}