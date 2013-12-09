#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        int c=0;
        for(int i=0;i<s.size();i++)
            if(isdigit(s[i]))c++;
        cout<<c<<endl;
    }
    return 0;
}
