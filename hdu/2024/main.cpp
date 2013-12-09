#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool isstart(char c){
    return isalpha(c)||c=='_';
}
bool isnonstart(char c){
    return isstart(c)||isdigit(c);
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        bool failed=false;
        if(!isstart(s[0]))failed=true;
        if(!failed){
            for(int i=1;i<s.size();i++){
                if(!isnonstart(s[i])){
                    failed=true;
                    break;
                }
            }
        }
        if(failed)cout<<"no"<<endl;
        else cout<<"yes"<<endl;

    }
    return 0;
}
