
#include <iostream>
// In this lab we will be solving the Max Subarray Problem via Divide-and-conqeuer

using namespace std;

int findMaxCrossingsubArray(int *A, int low, int mid, int high){
    int leftSum = INT32_MIN;
    int sum = 0;
    int maxLeft;

    for (int i = mid; i >= low; i--){
        sum += A[i];

        if (sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum = INT32_MIN;
    int sums = 0;
    int maxRight;
    
    for (int j = mid + 1; j <= high; j++){
        sums = sums + A[j];
        if (sums > rightSum){
            rightSum = sums;
            maxRight = j;
        }
    }

    if(maxLeft > maxRight && maxLeft > (leftSum + rightSum)){
        return maxLeft;
    }else if(maxRight > maxLeft && maxRight > (leftSum + rightSum)) {
        return maxRight;
    }else{
        return (leftSum+rightSum);
    }
}

int findMaxsubArray (int *A, int low, int high){
    if (high == low){
        if(low > high && low > A[low]){
            return low;
        }else if(high > low && high > A[low]) {
            return high;
        }else{
            return A[low];
        }
    }
    else {
        int mid = (low + high)/2;

        int leftSum = findMaxsubArray(A, low, mid);
        int rightSum = findMaxsubArray(A, mid + 1, high);
        int crossSum = findMaxCrossingsubArray(A, low, mid, high);

        if(leftSum >= rightSum && leftSum >= crossSum){
            return leftSum;
        }
        else if(rightSum >= leftSum && rightSum >= crossSum){
            return rightSum;
        }
        else {
            return crossSum;
        }
    }

}

int main(){
    //shiet i guess some things will go here, figure this out later LOLOLOLOLOLOLOLOLOL
    int *newArr;
    int arrSize = 1;

    cin >> arrSize;
    newArr = new int[arrSize];
    
    for(int i = 0; i < arrSize; i++){
        cin >> newArr[i];
    }
    int rand = findMaxsubArray(newArr, 0, arrSize - 1);
    cout << rand;
}