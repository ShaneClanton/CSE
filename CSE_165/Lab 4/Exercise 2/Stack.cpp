#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Stack.h"


int main() {
    int N;
    std::cin >> N;

    Stack stack;

    stack.initialize();
    for (int i = 0; i < N; i++){
        double val;
        std::cin >> val;

        stack.push(new double(val));
    }
    std::cout << std::endl;
    double *temp;
    while((temp = (double*)stack.pop()) != 0){
        std::cout << *temp << "\n";
        delete temp;
    }
    stack.cleanup();
    std::cout<<std::endl;
}
