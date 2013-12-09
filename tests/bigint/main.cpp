#include<iostream>
#include"bigint.hpp"
using namespace std;
void c(bigint& a, bigint& b){
    cout<<(a<b)
        <<(a==b)
        <<(a>b)
        <<(a<=b)
        <<(a>=b)
        <<endl;
}
int main(){
    // constructor test, ok
    bigint b1(2000001234),b2(string("41237468917489217461298471293"));
    cout<<b1<<endl<<b2<<endl;
    b2=b1;
    // comparision test, ok
    cout<<"[comparision]\n";
    c(b1,b2);
    c(b2,b1);
    b2=b1+b1;
    c(b1,b2);
    c(b2,b1);
    // addition, ok
    cout<<"[addition]\n";
    b1=b1+b1;
    cout<<b1<<endl;
    b1=b1+b1;
    cout<<b1<<endl;
    b1=b1+b1;
    cout<<b1<<endl;
    b1=b1+b1;
    cout<<b1<<endl;
    b1=b1+b1;
    cout<<b1<<endl;
    b1=b1+b1;
    cout<<b1<<endl;
    // multiplication, ok
    cout<<"[multiplication]\n";
    b1=b1*b1;
    cout<<b1<<endl;
    b1=b1*b1;
    cout<<b1<<endl;
    b1=b1*b1;
    cout<<b1<<endl;
    b1=b1*b1;
    cout<<b1<<endl;
    b1*=10;
    cout<<b1<<endl;
    // subtraction
    cout<<"[subtraction]\n";
    cout<<b1<<endl;
    cout<<b2<<endl;
    b1=b1-b2;
    cout<<b1<<endl;
    b1-=b2;
    cout<<b1<<endl;
    b1=bigint(10000)-bigint(1000);
    cout<<b1<<endl;
    // division
    cout<<"[division]\n";
    b1=b1/bigint(3);
    cout<<b1<<endl;
    b1=bigint(2034897234);
    b1=b1/bigint(3124);
    cout<<b1<<endl;
    
    return 0;
}

