#include <iostream>
#include "refs2.h"

using namespace std;

int main( int argc, const char * argv[] )
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	int* pnum;
	initialize_pint(pnum, num);

	cout << *pnum << endl;
	return 0;
}