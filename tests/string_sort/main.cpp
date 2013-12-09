#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int m[5],n[5];
string s[5]={"string","ios","mdyang","alfred","zero"};
// work wrongly
int _comp1(int i,int j){
    int r=s[i].compare(s[j]);
    cout<<"string::compare "<<s[i]<<" "<<s[j]<<" => "<<r<<endl;
    return r;
}
// work correctly
int comp1(int i,int j){
    int r=s[i].compare(s[j]);
    return r<0;
}
int comp2(int i,int j){
    int r=s[i]<s[j];
    cout<<s[i]<<"<"<<s[j]<<"="<<r<<endl;
    return r;
}
int main(){
    for(int i=0;i<5;i++){
        m[i]=i;
        n[i]=i;
    }
    sort(m,m+5,comp1);
    sort(n,n+5,comp2);
    for(int i=0;i<5;i++)cout<<s[m[i]]<<endl;
    for(int i=0;i<5;i++)cout<<s[n[i]]<<endl;
    return 0;
}
