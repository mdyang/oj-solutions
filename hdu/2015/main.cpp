#include<iostream>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        if(m>=n)cout<<n+1<<endl;
        else{
            int current=m+1;
            cout<<current;
            int c=n/m,incr=m*2;
            current+=incr;
            for(int i=1;i<c;i++,current+=incr)cout<<" "<<current;
            int r=n%m;
            if(r>0){
                current-=(m-r);
                cout<<" "<<current;
            }
            cout<<endl;
        }
    }
    return 0;
}
