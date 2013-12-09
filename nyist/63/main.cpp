#include<iostream>
#include<memory.h>
using namespace std;
const int MAX=524288;
bool s[MAX];
int d;

int put(){
    int c=1,_d=1;
    while(_d<d){
        bool b=s[c];
        s[c]=!b;
        c<<=1;
        _d++;
        if(b)c++;
    }
    return c;
}

int main(){
    int i;
    while(1){
        cin>>d>>i;
        if((d|i)==0)break;
        memset(s,false,sizeof(s));
        int j,res;
        for(j=0;j<i;j++) res=put();
        cout<<res<<endl;
    }
    return 0;
}
