#include<set>
#include<iostream>
using namespace std;
int main(){
    int m,n;
    while(1){
        cin>>m>>n;
        if((m|n)==0)break;
        int temp;
        set<int> s;
        while(m--){
            cin>>temp;
            s.insert(temp);
        }
        while(n--){
            cin>>temp;
            s.erase(temp);
        }
        if(s.size()==0)cout<<"NULL\n";
        else{
            for(set<int>::iterator i=s.begin();i!=s.end();i++)cout<<*i<<' ';
            cout<<endl;
        }
    }
    return 0;
}
