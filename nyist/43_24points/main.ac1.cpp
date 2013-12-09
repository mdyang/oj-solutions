#include <iostream>
#include <list>
#include <cmath>

using namespace std;

bool equal(double op1, double op2){
    if (abs(op1-op2) < 0.01) return true;
    return false;
}

void swap(list<double>::iterator& a, list<double>::iterator& b){
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tryit(list<double> &l,
        list<double>::iterator& i1,
        list<double>::iterator& i2,
        list<double>::iterator& ir,
        double result){
    i2 = l.erase(i2);
    i1 = l.erase(i1);
    ir = l.insert(i1, result);
}

void restore(list<double> &l,
        list<double>::iterator& i1, 
        list<double>::iterator& i2, 
        list<double>::iterator& ir, 
        double op1, double op2){
    // cout << "ir=" <<*ir<<",i1="<<op1<<",i2="<<op2<<endl;
    l.erase(ir);
    i1 = l.insert(i1, op1);
    i2 = l.insert(i2, op2);
    /*for (list<double>::iterator i = l.begin();
            i != l.end(); i ++){
        cout << *i << ' ';
    }
    cout << endl;
*/
}

bool has(list<double>& l, double N){
/*
    for (list<double>::iterator i = l.begin();
            i != l.end(); i ++){
        cout << *i << ' ';
    }
    cout << endl;
*/
    if (l.size()==1 && equal(*l.begin(), N)) return true;
    list<double>::iterator i1, i2;
    i1 = i2 = l.begin();
    for (i2++; i2 != l.end(); i1++, i2++){
        double op1 = *i1;
        double op2 = *i2;
        list<double>::iterator ir;

        tryit(l, i1, i2, ir, op1+op2);
        if (has(l, N)) return true;
        restore(l, i1, i2, ir, op1, op2);

        tryit(l, i1, i2, ir, op1-op2);
        if (has(l, N)) return true;
        restore(l, i1, i2, ir, op1, op2);

        tryit(l, i1, i2, ir, op1*op2);
        if (has(l, N)) return true;
        restore(l, i1, i2, ir, op1, op2);
        if (op2 != 0){
            tryit(l, i1, i2, ir, op1/op2);
            if (has(l, N)) return true;
            restore(l, i1, i2, ir, op1, op2);
        }
    }
    return false;
}

bool perm(list<double>& l, double N, int k, int n, list<double>::iterator i){
    if (k == n-1) {
        list<double> temp = l;
        return has(temp, N);
    }
    else{
        for (list<double>::iterator j = i; j != l.end(); j ++){
            swap(i, j);
            list<double>::iterator _i = i;
            _i ++;
            bool result = perm(l, N, k+1, n, _i);
            swap(i, j);
            if (result) return true;;
        }
        return false;
    }
}

int main(){

    int C;
    cin>>C;
    while (C--){
        list<double> l;
        int M, N;
        cin>>M>>N;
        while (M--){
            double temp;
            cin >> temp;
            l.push_back(temp);
        }
        if (perm(l, N, 0, l.size(), l.begin())) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
