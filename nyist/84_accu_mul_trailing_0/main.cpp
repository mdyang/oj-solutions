#include<iostream>
using namespace std;
int f(int c){
    int a=0;
    while(c){
        c/=5;
        a+=c;
    }
    return a;
}
int main(){
    int c;
    cin>>c;
    while(c--){
        int m;
        cin>>m;
        cout<<f(m)<<endl;
    }
    return 0;
}
