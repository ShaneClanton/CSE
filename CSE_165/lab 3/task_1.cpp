#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input, letter, uppercase;
    std::vector<std::string> separate, upper;
    while (true)
    {
        std::cout << "Please input as many words as you want(enter quit to end program): ";
        std::cin >> input;
        uppercase = input;
        transform(uppercase.begin(), uppercase.end(), uppercase.begin(), toupper);

        if (uppercase == "QUIT")
        {
            break;
        } else if (input.length() > 1)
        {
            separate.push_back(input);
            upper.push_back(uppercase);
        }else if (input.length() == 1)
        {
            letter = uppercase;

        }
        }

    for(int i = 0; i < separate.size(); i++)
    {
        if(letter[0] == upper[i][0])
        {
        std::cout << separate[i] << std::endl;
        }
    }
}