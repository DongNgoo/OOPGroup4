#pragma once
#include "bird.h"

class Penguin : public Bird {
private:
	string sound;

public:
	Penguin();
	Penguin(string n, string l, double w, int h);
	virtual ~Penguin() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Penguin::Penguin()
	: Bird("New Duck", "Location", 0.0, 0) {
	setSound("Honk!");
}
Penguin::Penguin(string n, string l, double w, int h)
	: Bird(n, l, w, h) {
	setSound("Honk!");
}

void Penguin::setSound(string s) { sound = s; }
string Penguin::getSound() const { return sound; }

void Penguin::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Penguin::displayReport() const {
	Bird::displayReport();
	cout 
		<< "Species: Penguin\n"
		<< "Sound: " << getSound() << endl;
}