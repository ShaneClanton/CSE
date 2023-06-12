#include <iostream>
#include "refs.h"
using namespace std;

int main( int argc, const char * argv[] )
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	triple(num);

	cout << num << endl;

	return 0;
}