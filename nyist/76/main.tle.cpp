#include<iostream>

using namespace std;
int count;
int m;
void f(){
    if(m==0)count++;
    for(int i=1;i<=2;i++){
        if(m>=i){
            m-=i;
            f();
            m+=i;
        }
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>m;
        m--;
        count=0;
        if(m==0){
            cout<<0<<endl;
            continue;
        }
        f();
        cout<<count<<endl;
    }
    return 0;
}
