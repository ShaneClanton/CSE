#include <iostream>

struct example1
{
    char c;
    double d;
};

struct example2
{
    char c, c2;
    double d;
};

struct example3
{
    char c, c2, c3;
    double d;
};

struct example4
{
    char c, c2, c3, c4;
    double d;
};

struct empty{};

struct example5
{
    char c;
    int i;
    char c2;
};

struct example6
{
    char c, c2;
    int i;
};

int main(){
    std::cout << sizeof(example1) << "\n";
    std::cout << sizeof(example2) << "\n";
    std::cout << sizeof(example3) << "\n";
    std::cout << sizeof(example4) << "\n";
    std::cout << sizeof(empty) << "\n";
    std::cout << sizeof(example5) << "\n";
    std::cout << sizeof(example6) << "\n";
    return 0;
}
