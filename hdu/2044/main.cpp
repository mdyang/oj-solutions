#include<iostream>
using namespace std;
unsigned long long ways[50];
int main(){
    ways[0]=ways[1]=1;
    for(int i=2;i<50;i++)ways[i]=ways[i-1]+ways[i-2];
    int n;cin>>n;while(n--){
        int i1,i2;cin>>i1>>i2;cout<<ways[i2-i1]<<endl;
    }
    return 0;
}
