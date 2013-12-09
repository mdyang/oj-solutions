#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m;
    while(m--){
        cin>>n;
        if(n==1){
            cout<<"1/1\n";
            continue;
        }
        int i,sum;
        for(i=1,sum=i*(i+1)/2;sum<n;i++,sum=i*(i+1)/2);
        sum-=i;
        n-=sum;
        if(i&1){
            cout<<i-n+1<<'/'<<n<<endl;
        }
        else{
            cout<<n<<'/'<<i-n+1<<endl;
        }
    }
    return 0;
}
