#include<iostream>
using namespace std;
int sum[55];
int main(){
    sum[1]=1;
    for(int i=2;i<5;i++)sum[i]=i;
    for(int i=5;i<55;i++)sum[i]=sum[i-1]+sum[i-3];
    int n;
    while(cin>>n){
        if(n==0)break;
        cout<<sum[n]<<endl;
    }
    return 0;
}
