#pragma once
#include "animal.h"

class Dog : public Animal {
public:
	Dog(string n = "New Dog", string s = "Bark!", double w = 0.0, int h = 0);
};

Dog::Dog(string n, string s, double w, int h)
	: Animal(n, s, w, h) {}