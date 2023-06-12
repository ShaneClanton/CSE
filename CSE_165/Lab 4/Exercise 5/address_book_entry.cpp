#include <iostream>
#include "Entry.h"

int main(int argc, const char * argv[])
{
	std::string name, lastname, email;

	std::cin >> name;
	std::cin >> lastname;
	std::cin >> email;

	Entry myEntry;

	myEntry.setName(name);
	myEntry.setLastname(lastname);
	myEntry.setEmail(email);

	myEntry.print();

	return 0;
}