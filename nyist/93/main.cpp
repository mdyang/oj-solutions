#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;
stack<int> s[3];
int main(){
    int N;
    cin>>N;
    while(N--){
        for(int i=0;i<3;i++){
            while(!s[i].empty())s[i].pop();
            s[i].push(INT_MAX);
        }
        int p,q;
        cin>>p>>q;
        for(int i=p;i>0;i--)s[0].push(i);
        bool fail=false;
        for(int i=0;i<q;i++){
            int from,to;
            cin>>from>>to;
            if(fail)continue;
            if(s[from-1].top()<s[to-1].top()){
                s[to-1].push(s[from-1].top());
                s[from-1].pop();
            }
            else fail=true;
        }
        if(fail)cout<<"illegal\n";
        else cout<<"legal\n";
    }
    return 0;
}
