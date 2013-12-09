#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        int cnt=0;
        for(int i=0;i<s.size();i++)
            if(s[i]<0)cnt++;
        cout<<cnt/2<<endl;
    }
    return 0;
}
