#include <iostream>

using namespace std;

int main(int argc, char **argv){

    int* Sequence;
    int arraySize, n, i, j, k;

    // Get the size of the sequence
    cin >> arraySize;
    Sequence = new int[arraySize];

    // Read the sequence
    for(int i=0; i<arraySize; i++){
        cin >> Sequence[i];
    }

    // Initialization of Insertion Sort
    for (i = 1; i < arraySize; i++){
        n = Sequence[i];
        j = i - 1;

        while (j >= 0 && Sequence[j] > n){
            Sequence[j + 1] = Sequence[j];
            j = j - 1;
        }

        Sequence[j + 1] = n;

        // Output
        for (k = 0; k <= i; k++){
            cout << Sequence[k] << ";";
        }
        cout << endl;
    }

    // Free alocated space
    delete[] Sequence;
}