#include <iostream>
#include "Object.h"

using namespace std;

int Object::count = 0;

Object f( Object& someObject ) // Modified: pass by reference instead of by value
{
    return someObject;
}

int main( int argc, const char * argv[] )
{
    Object myObject;

    Object another = f(myObject);

    cout << Object::count << endl; // Modified: use the class name to access the count variable

    return 0;
}
