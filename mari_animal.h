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
	string sound;
	double weight{ 0.0 };
	int hungerLevel{ 0 };

public:
	Animal(string n = "New Animal", string s = "Hello!", double w = 0.0, int h = 0);

	void setName(string n);
	string getName() const;

	void setSound(string s);
	string getSound() const;

	void setWeight(double w);
	double getWeight() const;

	void setHunger(int h);
	int getHunger() const;

	void playAnimal();
	void feedAnimal();
	void makeSound();
	void displayReport();
};

Animal::Animal(string n, string s, double w, int h)
	: name{ n }, sound{ s } {
	setWeight(w);
	setHunger(h);
}

void Animal::setName(string n) { name = n; }
string Animal::getName() const { return name; }

void Animal::setSound(string s) { sound = s; }
string Animal::getSound() const { return sound; }

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
void Animal::makeSound() {
	cout << "\n" << getName() << " says: " << getSound() << endl;
}
void Animal::displayReport() {
	cout
		<< "\nAnimal Report"
		<< "\nName: " << getName()
		<< "\nSound: " << getSound()
		<< "\nWeight: " << getWeight()
		<< "\nHunger level: " << getHunger()
		<< endl;
}