#pragma once
#include "mammal.h"

class Hippo : public Mammal {
private:
	string sound;

public:
	Hippo();
	Hippo(string n, string l, double w, int h);
	virtual ~Hippo() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Hippo::Hippo()
	: Mammal("New Hippo", "Location", 0.0, 0) {
	setSound("Growl!");
}
Hippo::Hippo(string n, string l, double w, int h)
	: Mammal(n, l, w, h) {
	setSound("Growl!");
}

void Hippo::setSound(string s) { sound = s; }
string Hippo::getSound() const { return sound; }

void Hippo::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Hippo::displayReport() const {
	Mammal::displayReport();
	cout 
		<< "Species: Hippopotamus\n"
		<< "Sound: " << getSound() << endl;
}