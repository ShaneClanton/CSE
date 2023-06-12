#ifndef ENTRY_H
#define ENTRY_H

#include <string>

struct Entry
{
    std::string myName, mylName, myemail;
    Entry* next;

    Entry(){
        myName = " ";
        mylName = " ";
        myemail = " ";
        next = NULL;
    }

    void setName(std::string fname){
        myName = fname;
    }

    void setLastname(std::string lname){
        mylName = lname;
    }

    void setEmail(std::string email){
        myemail = email;
    }

    std::string getName(){
        return myName;
    }
    std::string getLastName(){
        return mylName;
    }
    std::string getEmail(){
        return myemail;
    }

    void print(){
        std::cout << getName() << "," << getLastName() << "," << getEmail() << "\n";
    }
};

#endif
