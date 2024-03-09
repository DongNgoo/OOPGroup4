#include <vector>
#include "animal.h"
#include "dog.h"
using std::vector;

void addAnimal(vector<Animal*>& arr, Animal* ptr) {
	arr.push_back(ptr);
}

void displayZooReport(const vector<Animal*>& arr) {
	for (auto animal : arr) {
		animal->makeSound();
		animal->displayReport();
	}
}

int main() {
	vector<Animal*> animals{};
	Dog newDog("Scratch", "Rivington", 20.5, 7);
	Animal* ptrNewDog{ &newDog };

	addAnimal(animals, ptrNewDog);
	displayZooReport(animals);


	return 0;
}

