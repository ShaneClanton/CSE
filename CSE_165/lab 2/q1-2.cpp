#include <iostream>

using namespace std;

int main() 
{
    int input;
    int failsafe = 0;
    do {
        cout << "Please enter a number: ";
        cin >> input;
        if (input > 0){
            cout << "POSITIVE" << endl;
        } else if (input < 0){
            cout << "NEGATIVE" << endl;
        }
        if ((input % 2) == 0){
            cout << "EVEN" << endl;
        }else{
            cout << "ODD"<< endl;
        }
    } while (input != failsafe);
}