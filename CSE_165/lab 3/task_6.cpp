#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input, letter, upperCase;
    std::vector<std::string> separate, upper, found;
    while (true)
    {
        std::cout << "Please input as many words as you want(enter quit to end program): ";
        std::cin >> input;
        upperCase = input;
        transform(upperCase.begin(), upperCase.end(), upperCase.begin(), toupper);

        if (upperCase == "QUIT")
        {
            break;
        } else if (input.length() > 4)
        {
            separate.push_back(input);
            upper.push_back(upperCase);
        }else if (input.length() <= 3)
        {
            letter = upperCase;
            for (int i = 0; i < separate.size(); i++)
            {
                    if(letter[0] == upper[i][0])
                    {
                        found.push_back(separate[i]);
                    }
            }

        }
        }

    for(int i = 0; i < found.size(); i++)
    {
        std::cout << found[i] << std::endl;
    }
}