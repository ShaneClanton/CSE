#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int o) {
	int i, j, k;
    // Ln to contain the elements on the left and Rn to contain the elements on the right. 
	int Ln = m - l + 1;
	int Rn = o - m;

	// Create temp arrays and splits them into left half (left) and right half (right).
	int left[Ln], right[Rn];

	// Copy the data into the left half
	for (i = 0; i < Ln; i++) {
		left[i] = arr[l + i];
	}
	// Copy the data into the right half
	for (j = 0; j < Rn; j++) {
		right[j] = arr[m + 1 + j];
	}

	// Initializes the indexes for the 1st & 2nd subArr as well as the mergedArr
	i = j = 0;
	k = l;

	// Get the remainging left and right elements into arr[]
	while (i < Ln && j < Rn) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < Ln) {
		arr[k] = left[i]; 
        i++; 
        k++; 
    }

    while (j < Rn) { 
        arr[k] = right[j]; 
        j++; 
        k++; 
	}
}

void mergeSort(int arr[], int l, int o) {
	if (l < o) {
		// Get m which will split the array
		int m = (l+o)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, o);

		merge(arr, l, m, o);
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ";";
	}
}

int main() {
	int n;
	cin >> n;

	int arr [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1);
	print(arr, n);
}