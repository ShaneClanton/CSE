#include <iostream>

using namespace std;
// In this lab which is part 1 of 2, we will be implementing Heap Sort.
// Commented out some of the psuedo code as it just wasn't working with it. Also didn't know how to make a class for A.heapSize so i just got rid of it
int Left(int i){
    return((2 * i) + 1);
}

int Right(int i){
    return((2 * i) + 2);
}

// Checks if the l and r and the A[l] and A[r] are larger or smaller than the heapSize and if so then give largest l, r, or i.
// Or if largest doesn't equal i then swap between a temp swap, A[i] and A[largest].
void maxHeapify(int *A, int i, int heapSize){
    int largest = i;
    int l = Left(i);
    int r = Right(i);
  
    if (l < heapSize && A[l] > A[largest]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r < heapSize && A[r] > A[largest]){
        largest = r;
    }
    if (largest != i){
        int swap = A[i];
        A[i] = A[largest];
        A[largest] = swap;
        maxHeapify(A, largest, heapSize);
    }

   // return maxHeapify(A, i, heapSize, largest);
}
// function to build the Max Heap with heapSize and calls
// maxHeapify within the first for loop and then int the loop to swap the first element
// and the ith element that is currently selected.

/*
void buildMaxHeap(int *A, int i, int heapSize, int largest){
    for(int i = heapSize/2; i >= 1; i--){
        maxHeapify(A, i, heapSize);
    }
}
*/

void heapSort(int *A, int heapSize){
    for (int i = ((heapSize/2) - 1); i >= 0; i--){
        maxHeapify(A, i , heapSize);
    }

    for (int i = heapSize - 1; i >= 1; i--){
        int swap = A[0];
        A[0] = A[i];
        A[i] = swap;
        maxHeapify(A, 0, i);
    }
}

/*
void heapMaximum(int *A){
    return A[1];
}
// Function to extract the max from the heap.
void heapExtractMax(int *A){
    if(A.heapSize < 1){
        cout << "heap underflow";
    }

    int max = A[1];
    A[1] = A[A.heapSize];
    A.heapSize = A.heapSize - 1;
    maxHeapify(A, 1);
    return max;
}

// Function to increase the key in the heap.
void heapIncreaseKey(int *A, int i , int key){
    if (key < A[i]){
        cout << "new key is smaller than current key";
    }
    A[i] = key;
    while(i > 1 && A[PARENT(i) < A[i]]){
        A[i] = A[PARENT(i)];
        i = PARENT(i);
    }
}

// Function to insert the max into the heap.
void maxHeapInsert(int *A, int key){
    A.heapSize = A.heapSize + 1;
    A[A.heapSize] = INT32_MIN;              // INT32_MIN is just what I use for negative infinity
    heapIncreaseKey(A, A.heapSize, key);
}

// this build function differs from the previous one as A.heapSize gets 1 and calls
// maxHeapInsert within the for loop.
void buildMaxHeap(int *A){
    A.heapSize = 1;
    for(int i = 2; i <= A.length; i--){
        maxHeapInsert(A, A[i]);
    }
}
*/

// Main function that recieves the numbers entered and then printed out in order.
int main(){
    int *newArr;
    int arrSize = 1;

    cin >> arrSize;
    newArr = new int[arrSize];
    
    for(int i = 0; i < arrSize; i++){
        cin >> newArr[i];
    }
    
    heapSort(newArr, arrSize);

    for(int i = 0; i < arrSize; i++){
        cout << newArr[i] << ';';
    }


}