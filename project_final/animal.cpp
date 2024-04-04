#include<iostream>
#include<string>
#include<stdexcept>
#include<random>
#include<ctime>
#include"animal.h"

using std::string;

Animal::Animal()
	: name{ "New Animal" }, location{ "Location" }, weight{ 0.0 }, hungerLevel{ 0 } {
	setAnimalID();
}
Animal::Animal(string n, string l, double w, int h)
	: name{ n }, location{ l } {
	setAnimalID();
	setWeight(w);
	setHunger(h);
}

std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };

void Animal::setAnimalID() {
	std::uniform_int_distribution<unsigned int> randomInt{ 1000, 9999 };
	animalID = randomInt(engine);
}
int Animal::getAnimalID() const { return animalID; }

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
		<< "\n------------------------------"
		<< "\nAnimal ID: " << getAnimalID()
		<< "\nName: " << getName()
		<< "\nLocation of origin: " << getLocation()
		<< "\nWeight: " << getWeight()
		<< "\nHunger level: " << getHunger()
		<< endl;
}