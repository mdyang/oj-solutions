#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int eval(string&s,int base){
    int val=s[0]-'0';
    for(int i=1;i<s.length();i++){
        val*=base;
        val+=(s[i]-'0');
    }
    return val;
}
int findbase(string&s){
    int base=0;
    for(int i=0;i<s.length();i++){
        base=base<(s[i]-'0')?(s[i]-'0'):base;
    }
    return base+1;
}
int main(){
    int c;
    cin>>c;
    while(c--){
        string a,b,c;
        cin>>a>>b>>c;
        int base=max(findbase(a),max(findbase(b),findbase(c)));
        int succeed=false;
        while(base<=16){
            if(eval(a,base)*eval(b,base)==eval(c,base)){
                cout<<base<<endl;
                succeed=true;
                break;
            }
            base++;
        }
        if(!succeed){
            cout<<0<<endl;
        }
    }
    
    return 0;
}
