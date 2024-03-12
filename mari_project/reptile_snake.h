#pragma once
#include "reptile.h"

class Snake : public Reptile {
private:
	string sound;

public:
	Snake();
	Snake(string n, string l, double w, int h);
	virtual ~Snake() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Snake::Snake()
	: Reptile("New Snake", "Location", 0.0, 0) {
	setSound("Hiss!");
}
Snake::Snake(string n, string l, double w, int h)
	: Reptile(n, l, w, h) {
	setSound("Hiss!");
}

void Snake::setSound(string s) { sound = s; }
string Snake::getSound() const { return sound; }

void Snake::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Snake::displayReport() const {
	Reptile::displayReport();
	cout 
		<< "Species: Snake\n"
		<< "Sound: " << getSound() << endl;
}