#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
int cnt[6];
int index(char c){
    switch(c){
        case 'a':
        case 'A':return 0;
        case 'e':
        case 'E':return 1;
        case 'i':
        case 'I':return 2;
        case 'o':
        case 'O':return 3;
        case 'u':
        case 'U':return 4;
        default:return 6;
    }
}
char c[6]="aeiou";
int main(){
    int n;
    cin>>n;cin.ignore();
    bool first=true;
    while(n--){
        if(first)first=false;
        else cout<<endl;
        string s;
        getline(cin,s);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<s.size();i++)cnt[index(s[i])]++;
        for(int i=0;i<5;i++)cout<<c[i]<<':'<<cnt[i]<<endl;
    }
    return 0;
}
