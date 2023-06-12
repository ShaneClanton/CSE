#include <iostream>
#include <string>
#include <vector>


int main(){
    std::vector<std::vector<std::string> *> V;
    std::string input;
    
    for (int i = 0; i < 10; i++)
            {
            std::vector<std::string> *entries = new std::vector<std::string>;
            V.push_back(entries);
            }

    while(true)
    {
        std::cout << "Enter the input: ";
        std::cin >> input;
        if(input == "quit")
        {
            break;
        }
        V[input.length() - 1] -> push_back(input);
    }

    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i]->size(); j++)
        {
            std::cout << V[i]->at(j) << " ";
        }
        if(i != V.size() - 1)
        {
        std::cout << std::endl;
        }
    }
}