#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> values;
    int input, sum;

    std::cout << "Enter an integer: ";
    while (true)
    {
        std::cin >> input;
        if(input >= 1)
        {
        values.push_back(input);
        }
        else if (input == 0)
        {
            break;
        }else if(input < 0)
        {
                for (int i = 0; i < values.size(); i++)
                {
                    if(input * -1 == values[i])
                    {
                       values.erase(values.begin()+i);
                    }
                }
            }
    }
    sum = 0;
    for (int i = 0; i < values.size(); i++)
    {
        sum += values[i];
    }
    std::cout << values.size() << " " << sum << std::endl;
}