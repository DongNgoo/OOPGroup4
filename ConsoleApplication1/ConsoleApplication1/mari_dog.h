#pragma once
#include "mari_animal.h"

class Dog : public Animal {
private:
	string sound;
public:
	Dog(string n = "New Dog", string l = "Location", double w = 0.0, int h = 0, string s = "Bark!");
	void setSound(string s);
	string getSound() const;
	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Dog::Dog(string n, string l, double w, int h, string s)
	: Animal(n, l, w, h) {
	setSound(s);
}

void Dog::setSound(string s) { sound = s; }
string Dog::getSound() const { return sound; }

void Dog::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Dog::displayReport() const {
	Animal::displayReport();
	cout << "Sound: " << getSound() << endl;
}