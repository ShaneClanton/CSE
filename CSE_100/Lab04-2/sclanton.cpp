#include <iostream>
#include <stdlib.h>

using namespace std;
// In this lab we will be implementing quickSort.

// PARTITION to perform two swaps, one inside the for loop and one outside the for loop
// all to rearrange the the subarray of A[p..r].
int PARTITION(int *A, int p, int r){
   int x = A[r];
   int i = p - 1;

    for (int j = p; j <= r - 1; j++){
        if (A[j] <= x){
              i = i + 1;
              int swap = A[i];
              A[i] = A[j];
              A[j] = swap;
        }
    }
    int swap1;
    swap1 = A[i + 1];
    A[i + 1] = A[r];
    A[r] = swap1;
    return i + 1;}

/*
void quickSort(int *A, int p, int r){
    if ( p < r){
        int q = PARTITION(A, p , r);
        quickSort(A, p , q - 1);
        quickSort(A, q + 1, r);
    }
}
*/
// Here is where we choose the random pivot point which is what p + rand() % (r-p) is for
// and then perform another swap of A[r] and A[i]
// p being the low and r being the high in the 
int randomizedPartition(int *A, int p, int r){
    int i = p + rand() % (r - p);
    int swap;
    swap = A[r];
    A[r] = A[i];
    A[i] = swap;
    return PARTITION(A, p, r);
}

// under the condition of p < r we assign q with randomizedPartition as well as call
// randomizedQuickSort twice while also slightly adjusting the parameters.
int randomizedQuickSort(int *A, int p, int r){
    if (p < r){
    int q = randomizedPartition(A, p, r);
    randomizedQuickSort(A, p, q - 1);
    randomizedQuickSort(A, q + 1, r);
    }
    return 0;
}

/*
int hoarePartition(int *A, int p, int r){
    int x = A[p];
    int i = p - 1;
    int j = r + 1;
    while (true){
    repeat {
    j = j - 1;
    }
    until {
        A[j] <= x;
    }
    repeat{
        i = i + 1;
    }
    until {
        A[i] >= x;
    }
    if (i < j){
        A[i] = A[j];
    }
    }
    return j;
}


void tailRecursiveQuickSort(int *A, int p, int r){
    while(p < r) {
       int q = PARTITION (A, p ,r);
        tailRecursiveQuickSort(A, p , q - 1);
        p = q + 1;
    }
}
*/

// Here's main function that gets the array and prints it out, pretty much the same as the previous labs
int main(){
    int *newArr;
    int arrSize = 1;

    cin >> arrSize;
    newArr = new int[arrSize];
    
    for(int i = 0; i < arrSize; i++){
        cin >> newArr[i];
    }

    randomizedQuickSort(newArr, 0, arrSize - 1);

    for(int i = 0; i < arrSize; i++){
        cout << newArr[i] << ';';
    }
}