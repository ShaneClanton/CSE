#include <iostream>

using namespace std;

bool primeCheck(int N)
{
    if (N <= 1)
    {
        return false;
    }
 
    for (int i = 2; i < N; i++)
    {
        if (N % i == 0)
        {
            return false;
        }
    }
 
    return true;
}

void primePrint(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (primeCheck(i))
        {
            cout << i << endl;
        }
    }
}

int main()
{
    int N;

    cout << "Please enter a number: ";

    cin >> N;

    primePrint(N);
}
