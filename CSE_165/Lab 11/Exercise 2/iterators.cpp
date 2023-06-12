#include <iostream>
#include <math.h>

#include "dynArray.h"

using namespace std;

template <class A, class X>
void add_five ( A& a )
{
    for( int i = 0; i < 5; i++ )
        a.add( (X)( 2.0 * sin(double(i)) ) );
};

int main(int argc, const char * argv[])
{
    DynArray<float> fa;
    add_five<DynArray<float>,float>( fa );

    DynArray<int> ia;
    add_five<DynArray<int>,int>( ia );

    Iterator<DynArray<float>,float> fa_it( fa );
    for( fa_it.begin(fa); !fa_it.at_end(fa); fa_it.advance() )
        fa_it.print();
    

    Iterator<DynArray<int>,int> ia_it( ia );
    for( ia_it.begin(ia); !ia_it.at_end(ia); ia_it.advance() )
        ia_it.print();

    return 0;
}