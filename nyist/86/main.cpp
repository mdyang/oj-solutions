#include<hash_set>
#include<iostream>
using namespace std;
using namespace __gnu_cxx;

int main(){
    int m,n;
    cin>>m>>n;
    hash_set<int> s;
    while(m--){
        int temp;
        cin>>temp;
        s.insert(temp);
    }
    while(n--){
        int temp;
        cin>>temp;
        if(s.find(temp)==s.end())cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;

}
