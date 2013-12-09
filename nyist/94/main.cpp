#include<iostream>

using namespace std;

int main(){
    int c;
    cin>>c;
    while(c--){
        int m,n;
        cin>>m>>n;
        int sum=m;
        while(m/n){
            int temp = m/n;
            sum+=temp;
            m=m%n+temp;
        }
        cout<<sum<<endl;
    }
    return 0;
}
