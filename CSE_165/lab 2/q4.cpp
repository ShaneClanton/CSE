#include <iostream>

using namespace std;

int main()
{
    int input;
    while(input >= 0)
    {
        cout << "Please enter a number: ";
        cin >> input;
        if (input < 0)
        {
            break;
        }
        else
        {
            cout << "In hex: 0x"<< hex << input << endl;
            cout << "In binary: " << bitset<8>(input) << endl;
        }
    }

}