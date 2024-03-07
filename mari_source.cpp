#include "animal.h"
#include "dog.h"

int main() {
	Dog newDog("Scratch", "Rivington", "Bark, bark!!!", 20.5, 7);
	Animal* ptrAnimal{ &newDog };

	ptrAnimal->makeSound();
	ptrAnimal->displayReport();

	return 0;
}