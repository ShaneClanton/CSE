#include <iostream>
#include <vector>
using namespace std;

// In this lab we will be using the radixSort algorithm. And since we are asked to sort vectors we will have to use vector<int> since we need a dynamic array to store data.

// countingSort to count the sorting of the array A[].
void countingSort(vector<int>* A, int B, int k){
    vector<int>* outputArr = new vector<int>[B]; // outputArr will be the output array
    int i, C[4] = {0};

    // This for loop stores the number of occurences in C[].
    for(i = 0; i < B; i++){
        C[A[i][k] % 4]++; // compute the remainder of integer division, this is repeated a lot.
    }
    // Here we change C[i] so that it will contain the actual position of the digit in outputArr[].
    for (i = 1; i < 4; i++){
        C[i] += C[i - 1];
    }

    // Here is where the output array is built;
    for (i = B - 1; i >= 0; i--){
        outputArr[C[A[i][k] % 4] - 1] = A[i];
        C[A[i][k] % 4]--;
    }

    // Here A[] will get the contents of the sorted array from outputArr[].
    for (i = 0; i < B; i++){
        A[i] = outputArr[i];
    }
}

// The main function of radixSort which calls countingSort.
void radixSort(vector<int>* A, int B){
    int vectorSize = 10;
    for (int k = vectorSize - 1; k >= 0; k--){
        countingSort(A, B, k);
    }
}

// Main function which gets the inputs and prints the outputs.
int main(){
    int arrSize;
    cin >> arrSize;
    vector<int>* newArr = new vector<int>[arrSize];

    // for loop to recieve all the inputs being entered
    for (int i = 0; i < arrSize; i++){
        for (int j = 0; j < 10; j++){
            int val;
            cin >> val;

            newArr[i].push_back(val); // Pushing the elements into vector newArr from the back or end.
        }
    }
    // Call radixSort
    radixSort(newArr, arrSize);

    // for loop to print out v which gets the elements from newArr
    for (int i = 0; i < arrSize; i++){
        vector<int>::iterator vArr = newArr[i].begin(); // get the iterator to point to the initial element of the map container.
        // .end() returns an iterator which points to past the end element in the vector container
        while (vArr != newArr[i].end()){
            cout << *vArr << ';';
            vArr++;
        }
        cout << endl;
    }
}

