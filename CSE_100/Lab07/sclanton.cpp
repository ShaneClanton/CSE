#include <iostream>

using namespace std;

//in this lab we will be using Rod Cutting for Dynamic Programming.

void extended_Bottom_Cut_Rod(int p[], int n){
    int r[n + 1], s[n + 1]; // Here we're letting 'r[]' and 's[]' be new arrays.
    r[0] = 0;

    for(int j = 1; j <= n; j++){
        int q = INT32_MIN; // INT32_MIN is just what I use for whenver i'm asked to use negative infinity.
        for(int i = 1; i <=j; i++){
            if(q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
             r[j] = q;
        }
    }
    int length = n;

    cout << r[length] << endl;
    while(length > 0){
        cout << s[length] << " ";
        length = length - s[length];
    }
    cout << "-1" << endl;
}

int main(){
    // This is where we call everything as well as print everything in the format that is required.
   int n = 1;
   int *p;

   cin >> n;

   p = new int[n + 1];
   for(int i = 1; i <= n; i++){
       cin >> p[i];
   }
   extended_Bottom_Cut_Rod(p, n);
}

