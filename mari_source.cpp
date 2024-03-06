#include "animal.h"

int main() {
	Animal newAnimal;
	newAnimal.displayReport();

	Animal myDog("Ricky", "Bark!", 30.5, 5);
	myDog.displayReport();

	myDog.playAnimal();
	myDog.displayReport();

	return 0;
}