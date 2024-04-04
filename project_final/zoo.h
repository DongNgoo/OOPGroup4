#pragma once
#include <vector>
#include <algorithm>
#include "animal.h"

using std::vector;

class Zoo {
public:
	Zoo();
	~Zoo() {};
	void addInitialAnimals();
	void addAnimal();
	Animal* selectCategory();
	void removeAnimal();
	void displayZooReport();
	void searchAnimalByName();
	void feed();
	void play();
private:
	vector<Animal*> animals{};
};
