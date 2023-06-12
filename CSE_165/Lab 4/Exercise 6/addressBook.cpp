#include <iostream>
#include "AddressBook.h"
#include "Entry.h"

int main(int argc, const char * argv[])
{
	int n;

	std::cin >> n;

	std::string name, lastname, email;

	AddressBook myAddressBook;

	for(int i = 0; i < n; i++){
	std::cin >> name;
	std::cin >> lastname;
	std::cin >> email;

	Entry *entry = new Entry();
	entry->setName(name);
	entry->setLastname(lastname);
	entry->setEmail(email);
	myAddressBook.add(entry);
	}
	myAddressBook.print();

	return 0;
}