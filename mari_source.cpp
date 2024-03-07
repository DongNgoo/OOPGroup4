#include "animal.h"
#include "dog.h"

int main() {
	Animal newAnimal;
	newAnimal.displayReport();

	Animal myDog("Ricky", "Bark!", 30.5, 5);
	myDog.displayReport();

	myDog.playAnimal();
	myDog.makeSound();
	myDog.displayReport();

	Dog myDog_2;
	myDog_2.displayReport();

	Dog myDog_3("Scratch");
	myDog_3.displayReport();


	return 0;
}