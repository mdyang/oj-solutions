#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

void qselect(int* l, int left, int right, int n){
    if (left < right){
        int i = left - 1, j = right, pivot = l[right];
        while (i < j){
            do i++; while (l[i] < pivot);
            do j--; while (l[j] > pivot);
            if (i < j) swap(l[i], l[j]);
        }
        swap(l[i], l[right]);
        if (n < i-left) qselect(l, left, i-1, n);
        if (n > i-left+1) qselect(l, i+1, right, n-(i-left+1));
    }
}

class comparator{
    public:
       int operator()(const int& a, const int& b){
           return (a > b);
       }
};

int main(){

    int* l;
    int n, k;

    // test 20 times
    for (int i = 0; i < 20; i ++){
        int n = rand() % 1000000;
        int k = rand() % 100;
        if (n < k || k == 0) continue;
        cout << "Testing n=" << n << ", k=" << k << endl;
        l = new int[n];
        multiset<int, comparator> s;
        for (int j = 0; j < n; j ++){
            int temp = rand();
            l[j] = temp;            
            s.insert(temp);
            while (s.size() > k){
                s.erase(s.begin());
            }
        }
        qselect(l, 0, n-1, k);
        bool failed = false;
        for (int j = 0; j < k; j ++){
            if (s.find(l[j]) == s.end()){
                failed = true;
            }
        }
        if (failed) cerr << "Test Failed" << endl;
        else cout << "Test Passed" << endl;
        delete []l;
    }

    return 0;
}
