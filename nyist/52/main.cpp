#include <iostream>

using namespace std;

int ten[6] = {1,10,100,1000,10000,100000};
typedef unsigned long long ull;

int mulmod(ull a,ull b,int c){
    return (a*b)%c;
}

int main(){
    int c;
    cin>>c;
    while(c--){
        int n,k;
        cin>>n>>k;
        n%=ten[k];
        int i;
        int next;
        for(i=0,next=mulmod(n,n,ten[k]);i<ten[k]&&next!=n;next=mulmod(next,n,ten[k]),i++);
        if (next==n) cout<<i+1<<endl;
        else cout<<-1<<endl;
    }
}
