#include<iostream>

using namespace std;

typedef unsigned long long ull;

ull mulmod(ull,ull,ull);

// return a^b % c
ull expmod(ull a, ull b, ull c){
    if (b==0) return 1;
    if (b==1) return a%c;
    if (b&1) return mulmod(a,expmod(a,b-1,c),c);
    ull i = expmod(a,b/2,c);
    return mulmod(i,i,c);
}

// return a*b % c
ull mulmod(ull a, ull b, ull c){
    return ((a%c)*(b%c))%c;
}

int main(){

    ull a,b,c;
    int n;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        cout<<expmod(a,b,c)<<endl;
    }

    return 0;
}
