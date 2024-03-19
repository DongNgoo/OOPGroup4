#include "zoo.h"

int main() {
	Zoo z;
	z.addInitialAnimals();
	int menu;
	bool hasStuffToDo{ true };
	cout << "Welcome to the Zoo Management System!";

	while (hasStuffToDo) {
		cout
			<< "\n\n"
			<< "--------------------------------------------------\n"
			<< "| What would you like to do today?               |\n"
			<< "| 1. Display a report for all animals in the zoo |\n"
			<< "| 2. Display a report for a specific animal      |\n"
			<< "| 3. Add an animal to the zoo                    |\n"
			<< "| 4. Remove an animal from the zoo               |\n"
			<< "| 5. Feed an animal                              |\n"
			<< "| 6. Play with an animal                         |\n"
			<< "--------------------------------------------------\n"
			<< "\nEnter your selection: ";
		cin >> menu;

		switch (menu) {
		case 1:
			z.displayZooReport();
			break;
		case 2:
			z.searchAnimalByName();
			break;
		case 3:
			z.addAnimal();
			break;
		case 4:
			z.removeAnimal();
			break;
		case 5:
			z.feed();
			break;
		case 6:
			z.play();
			break;
		default:
			cout << "Invalid selection." << endl;
		}

		while (true) {
			int input;
			cout
				<< "\n\n"
				<< "--------------------------------------------------\n"
				<< "| Is there anything else you'd like to do today? |\n"
				<< "| 1. Yes                                         |\n"
				<< "| 2. No                                          |\n"
				<< "--------------------------------------------------\n"
				<< "\nEnter your selection: ";
			cin >> input;
			if (input == 1) {
				hasStuffToDo = true;
				break;
			}
			else if (input == 2) {
				hasStuffToDo = false;
				break;
			}
			else {
				cout << "\nInvalid selection." << endl;
			}
		}
	}

	cout << "\n\nThank you for using the Zoo Management System!" << endl;

	return 0;
}