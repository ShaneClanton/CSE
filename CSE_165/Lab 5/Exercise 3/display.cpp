#include <iostream>
#include <string>
#include <vector>
#include "display.h"



int main(int argc, const char * argv[])
{
    //
    int N;
    char c;
    std::string name;
    std::vector<Animal*> list;
    int num;

    std::cout << "Enter a number for N lines: ";
    std::cin >> N;
    std::cout << "Now enter a character (A or D), name and number separated by spaces:\n";

    for (int i = 0; i < N; i++)
    {
        std::cin >> c >> name >> num;
        if (c == 'A')
        {
            list.push_back(new Animal);
            list[i]->setName(name);
            list[i]->setAge(num);
        }else{
            Animal:Dog* pet = new Dog(name, num);
            list.push_back(pet);
        }
    }
    display(list);
    return 0;

}