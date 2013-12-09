#include<iostream>
using namespace std;
int m[41];
int main(){
    m[1]=m[2]=1;
    for(int i=3;i<41;i++)m[i]=m[i-1]+m[i-2];
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        cout<<m[t]<<endl;
    }
    return 0;
}
