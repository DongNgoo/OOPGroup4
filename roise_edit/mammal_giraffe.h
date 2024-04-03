#pragma once
#include "mammal.h"

class Giraffe : public Mammal {
private:
	string sound;

public:
	Giraffe();
	Giraffe(string n, string l, double w, int h);
	virtual ~Giraffe() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Giraffe::Giraffe()
	: Mammal("New Giraffe", "Location", 0.0, 0) {
	setSound("Hum!");
}
Giraffe::Giraffe(string n, string l, double w, int h)
	: Mammal(n, l, w, h) {
	setSound("Hum!");
}

void Giraffe::setSound(string s) { sound = s; }
string Giraffe::getSound() const { return sound; }

void Giraffe::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Giraffe::displayReport() const {
	Mammal::displayReport();
	cout 
		<< "Species: Giraffe\n"
		<< "Sound: " << getSound() << endl;
}