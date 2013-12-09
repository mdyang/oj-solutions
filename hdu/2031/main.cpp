#include<iostream>
using namespace std;
char buf[17];
int main(){
    int n,b;
    while(cin>>n>>b){
        int i=0;
        bool neg=n<0;
        if(n<0)n=-n;
        while(n){
            int m=n%b;
            buf[i++]=m>9?('A'+(m-10)):('0'+m);
            n/=b;
        }
        if(neg)cout<<'-';
        while(--i>=0)cout<<buf[i];cout<<endl;
    }
    return 0;
}
