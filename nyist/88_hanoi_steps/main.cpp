#include <iostream>

using namespace std;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull c){
    return a*b%c;
}

const ull MOD=1000000;

int modexp(ull a, ull b, ull c){
    if(b==0)return 1;
    if(b==1)return a%c;
    if(b&1)return modmul(modexp(a,b-1,c),a,c);
    int temp=modexp(a,b/2,c);
    return modmul(temp,temp,c);
}

int main(){

    int c;
    cin>>c;
    while(c--){
        ull temp;
        cin>>temp;
        cout<<modexp(2,temp,MOD)-1<<endl;
    }

    return 0;
}
