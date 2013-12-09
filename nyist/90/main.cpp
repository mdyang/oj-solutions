#include<iostream>
using namespace std;
int count;
void f(int n,int i){
    count++;
    for(int j=i;j<=n/2;j++){
        f(n-j,j);
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        count=1;
        int n;
        cin>>n;
        for(int i=1;i<=n/2;i++){
            f(n-i,i);
        }
        cout<<count<<endl;
    }
    return 0;
}
