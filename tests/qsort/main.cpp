#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int>& l, int i, int j){
    // cout << "swap " << i << ',' << j << endl;
    if (i != j){
        int temp = l[i];
        l[i] = l[j];
        l[j] = temp;
    }
}

void quick_sort(vector<int>& v, int l, int r){
    if (l < r){
        // cout << l << ',' << r << ' ' << endl;;
        int left = l-1;
        int right = r;
        int pivot = v[r];
        while (left < right){
            do { left++; } while (left < r && v[left] < pivot);
            // why v[right] >= pivot won't work here?
            do { right--; } while (right > l && v[right] > pivot);
            // cout << left << ',' << right << endl;
            if (left < right) {
                // cout << "left < right" << endl;
                swap(v, left, right);
            }
        }
        // cout << "left < r, " << left << ' ' << r << endl;
        swap(v, left, r);
        quick_sort(v, l, left-1);
        quick_sort(v, left+1, r);
    }
}

void test(int n){
    cout << "array size = " << n << endl;
    vector<int> v1, v2;
    for (int i = 0; i < n; i ++){
        int r = rand();
        v1.push_back(r);
        v2.push_back(r);
    } 
    quick_sort(v1, 0, n-1);
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i ++){
        if (v1[i] != v2[i]) {
            cerr << "Test Failed" << endl;
            return;
        }
    }
    cout << "Test Passed" << endl;
}

int main(){
    for (int i = 0; i < 20; i ++){
        test(rand() % 524288);        
    }
/*
    vector<int> v;
    for (int i = 0; i < 10000; i ++){
        v.push_back(rand());
    }
    quick_sort(v, 0, v.size()-1);
    for (int i = 0; i < 10000; i ++){
        cout << v[i] << ' ';
    }
    cout << endl;*/

    return 0;
}


