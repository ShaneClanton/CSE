#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{ 
    string name;
    int age;
    public:

Dog(string name, int age) {
		cout << "Creating Dog" << endl;
		setName(name);
        setAge(age);
	}
	
~Dog() {
	cout << "Deleting Dog" << endl;
}

string getName()
{
    return name;
}
int getAge()
{
    return age;
}

void feed () 
{ 
    cout<< "Dog food, please!\n"; 
}

};

#endif