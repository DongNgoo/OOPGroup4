#pragma once
#include<iostream>
#include<string>
#include<stdexcept>

using std::cout;
using std::endl;
using std::string;

class Animal {
private:
	string name;
	string location;
	double weight{ 0.0 };
	int hungerLevel{ 0 };

public:
	Animal(string n = "New Animal", string l = "Location", double w = 0.0, int h = 0);

	void setName(string n);
	string getName() const;

	void setLocation(string l);
	string getLocation() const;

	void setWeight(double w);
	double getWeight() const;

	void setHunger(int h);
	int getHunger() const;

	void playAnimal();
	void feedAnimal();

	virtual void makeSound() const = 0;
	virtual void displayReport() const;
};

Animal::Animal(string n, string l, double w, int h)
	: name{ n }, location{ l } {
	setWeight(w);
	setHunger(h);
}

void Animal::setName(string n) { name = n; }
string Animal::getName() const { return name; }

void Animal::setLocation(string l) { location = l; }
string Animal::getLocation() const { return location; }

void Animal::setWeight(double w) {
	if (w < 0.0) {
		throw std::invalid_argument("Weight must be larger than 0.0");
	}
	weight = w;
}
double Animal::getWeight() const { return weight; }

void Animal::setHunger(int h) {
	if (0 > h || h > 10) {
		throw std::invalid_argument("Hunger level must be larger than 0, and smaller than 10");
	}
	hungerLevel = h;
}
int Animal::getHunger() const { return hungerLevel; }

void Animal::playAnimal() {
	int currentHunger = getHunger();
	if (currentHunger) {
		setHunger(--currentHunger);
	}
}
void Animal::feedAnimal() {
	int currentHunger = getHunger();
	if (currentHunger < 10) {
		setHunger(10);
	}
}
void Animal::displayReport() const {
	cout
		<< "\nAnimal Report"
		<< "\nName: " << getName()
		<< "\nLocation of origin: " << getLocation()
		<< "\nWeight: " << getWeight()
		<< "\nHunger level: " << getHunger()
		<< endl;
}