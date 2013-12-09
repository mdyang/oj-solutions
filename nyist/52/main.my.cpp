#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ull;
int ten[6] = {1,10,100,1000,10000,100000};

int mulmod(ull a, ull b, int c){
    return (a*b)%c;
}

int main(){
    ull c;
    cin>>c;
    while(c--){
        int n,k;
        map<int,int> s;
        cin>>n>>k;
        n%=ten[k];
        if (n==1){
            cout<<1<<endl;
            continue;
        }
        int len=1;
        s[n]=len;
        int next=n;
        while(s[next=mulmod(next,n,ten[k])]==0){
            s[next]=++len;
        }
        cout<<len-s[next]+1<<endl;
    }
    return 0;
}
