#include<iostream>
#include<memory.h>
using namespace std;
bool sec[4];
int index(char c){
    if(c>='a'&&c<='z')return 0;
    if(c>='A'&&c<='Z')return 1;
    if(c>='0'&&c<='9')return 2;
    return 3;
}
int main(){
    int n;cin>>n;cin.ignore();while(n--){
        string s;getline(cin,s);
        memset(sec,0,sizeof(sec));
        for(int i=0;i<s.size();i++)sec[index(s[i])]=true;
        int c=0;
        for(int i=0;i<4;i++)if(sec[i])c++;
        if(c>=3&&s.size()>=8&&s.size()<=16)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}
