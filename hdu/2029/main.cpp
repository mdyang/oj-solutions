#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int l=s.size()/2,r;
        if(s.size()&1)r=l;
        else{
            r=l;l--;
        }
        bool failed=false;
        for(;l>=0;l--,r++)
            if(s[l]!=s[r])failed=true;
        if(failed)cout<<"no";
        else cout<<"yes";
        cout<<endl;
    }
    return 0;
}

