#pragma once
#include "bird.h"

class Duck : public Bird {
private:
	string sound;

public:
	Duck();
	Duck(string n, string l, double w, int h);
	virtual ~Duck() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

Duck::Duck()
	: Bird("New Duck", "Location", 0.0, 0) {
	setSound("Quack!");
}
Duck::Duck(string n, string l, double w, int h)
	: Bird(n, l, w, h) {
	setSound("Quack!");
}

void Duck::setSound(string s) { sound = s; }
string Duck::getSound() const { return sound; }

void Duck::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Duck::displayReport() const {
	Bird::displayReport();
	cout 
		<< "Species: Duck\n"
		<< "Sound: " << getSound() << endl;
}