#pragma once
#include <vector>
#include <algorithm>
#include "animal.h"
#include "mammal_elephant.h"
#include "mammal_giraffe.h"
#include "mammal_hippo.h"
#include "mammal_lion.h"
#include "mammal_lion_westAfrica.h"
#include "bird_duck.h"
#include "bird_eagle.h"
#include "bird_penguin.h"
#include "reptile_alligator.h"
#include "reptile_snake.h"
#include "reptile_tortoise.h"

using std::vector;
using std::remove_if;
using std::cin;

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

Zoo::Zoo() : animals{} {}

void Zoo::addInitialAnimals() {
	animals.push_back(new Lion("Simba", "Africa", 120.5, 8));
	animals.push_back(new Elephant("Dumbo", "Circus", 200.57, 7));
	animals.push_back(new Duck("Donald", "Toon Town", 12.5, 5));
}

Animal* Zoo::selectCategory() {
	int s;
	cout
		<< "\n\n********** ADD ANIMAL **********\n"
		<< "\nChoose the category of animal you'd like to add.\n\n"
		<< "-- Mammals --\n"
		<< "1. Elephant\n" << "2. Giraffe\n" << "3. Hippo\n" << "4. Lion\n\n"
		<< "-- Birds --\n"
		<< "5. Duck\n" << "6. Eagle\n" << "7. Penguin\n\n"
		<< "-- Reptiles --\n"
		<< "8. Alligator\n" << "9. Snake\n" << "10. Tortoise\n"
		<< "\nEnter your selection: ";
	cin >> s;

	Animal* ptr = nullptr;

	switch (s) {
	case 1:
		ptr = new Elephant();
		break;
	case 2:
		ptr = new Giraffe();
		break;
	case 3:
		ptr = new Hippo();
		break;
	case 4:
		while (true) {
			int input;
			cout
				<< "\nWhich lion would you like to add?\n"
				<< "1. Regular Lion\n"
				<< "2. West African Lion\n"
				<< "\nEnter your selection: ";
			cin >> input;
			if (input == 1) {
				ptr = new Lion();
				break;
			}
			else if (input == 2) {
				ptr = new WestAfricanLion();
				break;
			}
			else {
				cout << "\nInvalid selection." << endl;
			}
		}		
		break;
	case 5:
		ptr = new Duck();
		break;
	case 6:
		ptr = new Eagle();
		break;
	case 7:
		ptr = new Penguin();
		break;
	case 8:
		ptr = new Alligator();
		break;
	case 9:
		ptr = new Snake();
		break;
	case 10:
		ptr = new Tortoise();
		break;
	default:
		cout << "Invalid selection." << endl;
	}

	return ptr;
}

void Zoo::addAnimal() {
	string name, location;
	double weight;
	int hunger;
	Animal* ptr = selectCategory();


	cout << "\n\nEnter the following information.\nName (One word): ";
	cin >> name;
	ptr->setName(name);

	cout << "\nLocation of origin (One word): ";
	cin >> location;
	ptr->setLocation(location);

	while (true) {
		cout << "\nWeight: ";
		cin >> weight;
		try {
			ptr->setWeight(weight);
			break;
		}
		catch (std::invalid_argument& e) {
			cout << e.what() << endl;
		}
	}

	while (true) {
		cout << "\nHunger level: ";
		cin >> hunger;
		try {
			ptr->setHunger(hunger);
			break;
		}
		catch (std::invalid_argument& e) {
			cout << e.what() << endl;
		}
	}

	animals.push_back(ptr);
	cout << "\n\nThe following animal has been added to the zoo:";
	ptr->displayReport();
}

void Zoo::removeAnimal() {
	string n;
	cout 
		<< "\n\n********** REMOVE ANIMAL **********\n"
		<< "\nEnter the name of the animal you'd like to remove from the zoo: ";
	cin >> n;
	auto it = remove_if(animals.begin(), animals.end(), [&n](auto an) {
		return an->getName() == n;
	});
	if (it != animals.end()) {
		animals.erase(it, animals.end());
		cout << "\n\nAnimal named \"" << n << "\" has been removed from the zoo." << endl;
	}
	else {
		cout << "\n\nAnimal named \"" << n << "\" was not found in the zoo." << endl;
	}
	cout << "Displaying an updated zoo report:\n";
	displayZooReport();
}

void Zoo::displayZooReport() {
	cout << "\n\n********** DISPLAYING ZOO REPORT **********\n" << endl;
	for (auto animal : animals) {
		animal->displayReport();
	}
}

void Zoo::searchAnimalByName() {
	bool found = false;
	string n;
	cout 
		<< "\n\n********** ANIMAL SEARCH **********\n"
		<< "\nEnter the name of the animal you'd like generate a report of: ";
	cin >> n;
	for (auto animal : animals) {
		if (animal->getName() == n) {
			cout
				<< "\n\n...Searching the animal list for the name \"" << n << "\"..."
				<< "\nAnimal found:";
			animal->displayReport();
			found = true;
		}
	}
	if (!found) {
		cout << "Animal with name \"" << n << "\" not found in the zoo." << endl;
	}
}

void Zoo::feed() {
	bool found = false;
	string n;
	cout 
		<< "\n\n********** FEED ANIMAL **********\n"
		<< "\nEnter the name of the animal you'd like to feed: ";
	cin >> n;
	for (auto animal : animals) {
		if (animal->getName() == n) {
			cout
				<< "\n\n...Searching the animal list for the name \"" << n << "\"..."
				<< "\nAnimal found. Feeding " << n << "...\n\n";
			animal->feedAnimal();
			cout << n << " has been fed! Displaying an updated report for " << n << ": \n";
			animal->displayReport(); 
			found = true;
		}
	}
	if (!found) {
		cout << "Animal with name \"" << n << "\" not found in the zoo." << endl;
	}
}

void Zoo::play() {
	bool found = false;
	string n;
	cout 
		<< "\n\n********** PLAY WITH ANIMAL **********\n"
		<< "\nEnter the name of the animal you'd like to play with: ";
	cin >> n;
	for (auto animal : animals) {
		if (animal->getName() == n) {
			cout
				<< "\n\n...Searching the animal list for the name \"" << n << "\"..."
				<< "\nAnimal found. Playing with " << n << "...\n\n";
			animal->makeSound();
			animal->playAnimal();
			cout << n << " has got some exercise! Displaying an updated report for " << n << ": \n";
			animal->displayReport();
			found = true;
		}
	}
	if (!found) {
		cout << "Animal with name \"" << n << "\" not found in the zoo." << endl;
	}
}