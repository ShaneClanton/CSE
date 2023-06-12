#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "Entry.h"
#include <vector>

struct AddressBook{
    Entry* head;

    AddressBook(){
        head = NULL;
    }

    void add(Entry *entry){
        entry->next = head;
        head = entry;
    }

    void print(){
        Entry* entry;
        entry = head;
        while(entry != NULL){
            std::cout << entry->getName() << "," << entry->getLastName() << "," << entry->getEmail() << "\n";
            entry = entry->next;
        }
    }
};

#endif