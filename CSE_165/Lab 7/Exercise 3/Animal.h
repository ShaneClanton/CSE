#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
	std::string name;
	int age;

public:
	Animal() {
		name = "Generic Name";
		age = 0;
	}

	Animal( std::string n, int a ) {
		name = n;
		age = a;
	}

	virtual void talk(){}
};

#endif