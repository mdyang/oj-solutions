#include<iostream>
using namespace std;
int c[31];
int main(){
    c[0]=3;
    for(int i=1;i<31;i++)c[i]=(c[i-1]-1)*2;
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        cout<<c[t]<<endl;
    }
    return 0;
}
