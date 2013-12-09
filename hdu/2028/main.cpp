#include<iostream>
using namespace std;
unsigned long gcd_internal(unsigned long a,unsigned long b);
unsigned long gcd(unsigned long a,unsigned long b){
    if(a<b)return gcd_internal(b,a);
    return gcd_internal(a,b);
}
unsigned long gcd_internal(unsigned long a,unsigned long b){
    if(b==0)return a;
    return gcd_internal(b,a%b);
}
void update(unsigned long&a,unsigned long b){
    unsigned long g=gcd(a,b);
    a=a*b/g;
}
int main(){
    unsigned long n;
    while(cin>>n){
        
        unsigned long a=1,b;
        while(n--){
            cin>>b;
            update(a,b);
        }
        cout<<a<<endl;
    }
    return 0;
}
