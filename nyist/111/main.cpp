#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b); 
}
int main(){
    string s;
    while(cin>>s){
        int n1,n2,n3,n4;
        n1=s[0]-'0';
        n2=s[2]-'0';
        n3=s[4]-'0';
        n4=s[6]-'0';
        int base=gcd(n2,n4);
        int new_base=n2*n4/base;
        n1*=(new_base/n2);
        n3*=(new_base/n4);
        if(s[3]=='+')n1+=n3;
        else n1-=n3;
        bool sign=(n1<0);
        if(sign)n1=-n1;
        int f=gcd(n1,new_base);
        if(n1==0)cout<<"0\n";
        else
        {
            cout<<((sign)?"-":"")<<n1/f;
            if(new_base/f!=1)
                cout<<'/'<<new_base/f;
            cout<<endl;
        }
    }
    return 0;
}
