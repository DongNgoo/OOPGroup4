#pragma once
#include "bird.h"

class Eagle : public Bird {
private:
	string sound;

public:
	Eagle();
	Eagle(string n, string l, double w, int h);
	virtual ~Eagle() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Eagle::Eagle()
	: Bird("New Eagle", "Location", 0.0, 0) {
	setSound("Screech!");
}
Eagle::Eagle(string n, string l, double w, int h)
	: Bird(n, l, w, h) {
	setSound("Screech!");
}

void Eagle::setSound(string s) { sound = s; }
string Eagle::getSound() const { return sound; }

void Eagle::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Eagle::displayReport() const {
	Bird::displayReport();
	cout 
		<< "Species: Eagle\n"
		<< "Sound: " << getSound() << endl;
}