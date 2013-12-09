#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull times[41];
int main(){
    times[1]=0;
    times[2]=1;
    times[3]=2;
    for(int i=4;i<=40;i++)times[i]=times[i-1]+times[i-2];
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        cout<<times[m]<<endl;
    }
    return 0;
}
