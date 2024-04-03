#pragma once
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Animal {
private:
	int animalID;
	string name;
	string location;
	double weight{ 0.0 };
	int hungerLevel{ 0 };

public:
	Animal();
	Animal(string n, string l, double w, int h);
	virtual ~Animal() = default;

	void setAnimalID();
	int getAnimalID() const;

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
