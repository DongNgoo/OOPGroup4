#pragma once
#include "mammal_lion.h"

class WestAfricanLion : public Lion {
private:
	string sound;

public:
	WestAfricanLion();
	WestAfricanLion(string n, string l, double w, int h);
	virtual ~WestAfricanLion() = default;

	void setSound(string s);
	string getSound() const;

	virtual void makeSound() const override;
	virtual void displayReport() const override;
};

WestAfricanLion::WestAfricanLion()
	: Lion("New West African Lion", "West Africa", 0.0, 0) {
	setSound("Roarrr!");
}
WestAfricanLion::WestAfricanLion(string n, string l, double w, int h)
	: Lion(n, l, w, h) {
	setSound("Roarrr!");
}

void WestAfricanLion::setSound(string s) { sound = s; }
string WestAfricanLion::getSound() const { return sound; }

void WestAfricanLion::makeSound() const {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void WestAfricanLion::displayReport() const {
	Mammal::displayReport();
	cout
		<< "Species: West African Lion\n"
		<< "Sound: " << getSound() << endl;
}