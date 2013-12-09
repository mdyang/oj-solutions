#include <iostream>
#include <cmath>

using namespace std;

double delta = 1e-10;

bool equal(double a, double b){
    if (abs(a-b) < delta) return true;
    return false;
}

void find(double* l, double result, int n){
    if (n==1) if (equal(l[0], result)) throw true;
    for (int i = 0; i < n-1; i ++){
        swap(l[i], l[n-1]);
        for (int j = i; j < n-1; j ++){
            double temp = l[j];
            l[j] = temp + l[n-1];
            find(l, result, n-1);
            l[j] = temp - l[n-1];
            find(l, result, n-1);
            l[j] = l[n-1] - temp;
            find(l, result, n-1);
            l[j] = temp * l[n-1];
            find(l, result, n-1);
            if (temp){
                l[j] = l[n-1] / temp;
                find(l, result, n-1);
            }
            if (l[n-1]){
                l[j] = temp/l[n-1];
                find(l, result, n-1);
            }
            l[j] = temp;
        }
        swap(l[i], l[n-1]);
    }
}

double l[5];

int main(){

    int C;
    cin>>C;
    while(C--){
        int M;
        double N;
        cin>>M>>N;
        for (int i = 0; i < M; i ++){
            cin>>l[i];
        }
        try{
            find(l,N,M);
            cout << "No" << endl;
        }catch(...){
            cout << "Yes" << endl;
        }
    }
}
