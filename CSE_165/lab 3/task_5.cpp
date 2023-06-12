#include <iostream>
#include <string>
#include <vector>


int main(){
    std::vector<std::vector<std::string> *> V;
    std::string input;
    int counter = 1;

    while(true)
    {

        for (int i = 0; i < 10; i++){
            std::vector<std::string> *entries = new std::vector<std::string>;
            V.push_back(entries);
        }
        std::cout << "Enter the input: ";
        std::cin >> input;
        if(input == "quit")
        {
            std::cout << "Output:\n";
            break;
        }
        V[input.length() - 1] -> push_back(input);
    }

    for (int i = 0; i < V.size(); i++)
    {
        if(V[i]->size() == 0)
        {
            continue;
        }

        for (int j = 0; j < V[i]->size(); j++)
        {
            int total = V[i]->size() * V[i]->at(j).length();
            std::cout << total << " " << counter * V[i]->size() << "\n";
            break;
        }
    }
}