#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int input1, input2;
    cout << "Please enter a number: ";
    cin >> input1;
    cout << "Please enter another number: ";
    cin >> input2;
    int *p_input1 = &input1, *p_input2 = &input2;
    cout << *p_input1 << " + " << *p_input2 << " = " << (*p_input1 + *p_input2) << endl;
    cout << *p_input1 << " - " << *p_input2 << " = " << (*p_input1 - *p_input2) << endl;
    cout << *p_input1 << " * " << *p_input2 << " = " << (*p_input1 * *p_input2) << endl;
    cout << *p_input1 << " / " << *p_input2 << " = " << static_cast<float>(*p_input1) / *p_input2 << endl;
}