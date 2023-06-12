#include <string>
#include <iostream>
#include "Stash.h"
#include <fstream>

int main(){
    int inc, num;
    int x = 0;
    char ind = '\n';
    char c;

    std::cin >> inc;
    Stash stash;
    stash.initialize(sizeof(char), inc);

    while (true)
    {
        std::cin >> c >> num;
        if (c == '&' && num == 99)
        {
            break;
        }else{
        x = 0;
        for (int i = 0; i < abs(num); i++){
            stash.add(&c);
            if (num < 0 && x == 0 && (i+1) == abs(num)){
                stash.add(&ind);
                x++;
                }
            }
        } 
    }
    std::cout<<std::endl;
    for (int i = 0; i < stash.count(); i++)
    {
       std::cout << *((char *)stash.fetch(i));
    }

    std::cout << std::endl << stash.inflateCount << " " << stash.quantity << std::endl;

    stash.cleanup();

    return 0;
}