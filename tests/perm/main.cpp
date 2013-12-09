#include <iostream>

using namespace std;

void swap(char* arr, int i, int j){
    // cout << "swap, i=" << i << ", j=" << j << endl;
    if (i != j){
        // cout << "s1" << endl;
        char temp = arr[i];
        // cout << "s2" << endl;
        arr[i] = arr[j];
        // cout << "s3" << endl;
        arr[j] = temp;
    }
}

void perm(char* arr, int k, int n){
    // cout << "k=" << k << endl;
    if (k == n-1) cout << arr << endl;
    else{
        // cout << "else" << endl;
        for (int i = k; i < n; i ++){
            // cout << "k=" << k << ", i=" << i << endl;
            swap(arr, i, k);
            perm(arr, k+1, n);
            swap(arr, i, k);
        }
    }
}



int main(){

    char arr[5] = "abcd";

    perm(arr,0,4);
    return 0;
}
