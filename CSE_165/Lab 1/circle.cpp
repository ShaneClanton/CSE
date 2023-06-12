#include <iostream>

using namespace std;

int main()
{
	//cout << "Hello World" << endl;
	float rad, area;
    const float PI = 3.14159265;

	cout << "Please enter the radius of a circle: ";

	cin >> rad;

    area = PI*rad*rad;

    cout << "The area of the circle is: " << area << endl;
	
	return 0;
}