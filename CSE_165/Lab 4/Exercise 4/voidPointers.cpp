#include <iostream>
#include "Stack.h"



using namespace std;


void delete_func(void * pt){
    double * dpt = (double *)pt;
    cout<<"Deleting: " << * dpt << "\n";
    delete dpt;
}


int main(int argc, const char * argv[])
{
    Stack * doubleStack = new Stack;
	
	doubleStack->initialize();
    
    double value;
	int n;
	
	cin >> n;
	for (int i=0; i < n; i++){
		cin >> value;
        doubleStack->push(new double(value));
	}
    cout<<"\n";
    doubleStack->peek();
    cout<< endl;
    
    void (*del_func_ptr)(void * pt) = delete_func;
    
    doubleStack->setDeleteCallback(del_func_ptr);
    
    
    doubleStack->cleanup();
    cout<<endl;
    return 0;
}
