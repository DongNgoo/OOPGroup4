#pragma once
#include "reptile.h"

class Tortoise : public Reptile {
private:
	string sound;

public:
	Tortoise();
	Tortoise(string n, string l, double w, int h);
	virtual ~Tortoise() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Tortoise::Tortoise()
	: Reptile("New Tortoise", "Location", 0.0, 0) {
	setSound("Grunt!");
}
Tortoise::Tortoise(string n, string l, double w, int h)
	: Reptile(n, l, w, h) {
	setSound("Grunt!");
}

void Tortoise::setSound(string s) { sound = s; }
string Tortoise::getSound() const { return sound; }

void Tortoise::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Tortoise::displayReport() const {
	Reptile::displayReport();
	cout 
		<< "Species: Tortoise\n"
		<< "Sound: " << getSound() << endl;
}