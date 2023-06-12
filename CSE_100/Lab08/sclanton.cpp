#include <iostream>

#include <vector>
#include <string>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int size;
//tables m and s will be 1st and 2nd matricies

void matrix_chain_order(int p[], vector<vector<int>> &m, vector<vector<int>> &s) {
	int n = m.size();

	for (int i = 1; i < n; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l < n; l++) {
		for (int i = 1; i < n - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void print_optimal_parens(vector<vector<int>> s, int i, int j){
    if (i == j){
        cout << "A" << (i - 1);
    }
    else {
        cout << "(";
        print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j] + 1, j);
		cout << ")";
    }
}

int main() {
	cin >> size;
	int val[size];

	for (int i = 0; i <= size; i++) {
		cin >> val[i];
	}

	vector<vector<int>> m(size + 1, vector<int>(size + 1, 0)); //creating matrices
	vector<vector<int>> s(size + 1, vector<int>(size + 1, 0)); //vector of vector

	matrix_chain_order(val, m, s);
	cout << m[1][size] << endl;

	print_optimal_parens(s, 1, size);
	cout << endl;

	return 0; 
}