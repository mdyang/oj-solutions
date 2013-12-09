#include<set>
#include<iostream>
using namespace std;
int main(){
    int n,m,t;
    while((cin>>n>>m)&&(n|m)!=0){
        multiset<int> s;
        for(int i=0;i<n;i++){
            cin>>t;s.insert(t);
        }
        s.insert(m);
        set<int>::iterator i=s.begin();
        i++;
        cout<<*s.begin();
        for(;i!=s.end();i++)cout<<" "<<*i;
        cout<<endl;
    }
    return 0;
}
