#include<iostream>
#include<ext/hash_map>
#include<string>
using namespace std;
using namespace __gnu_cxx;
namespace __gnu_cxx{
    template<> struct hash<string>{
        size_t operator()(const string& x)const{
            return hash<const char*>()(x.c_str());
        }
    };
}
int main(){
    while(1){
        int n;
        cin>>n;
        if(!n)break;
        hash_map<string,int> m;
        int max=0;
        string b;
        while(n--){
            string s;
            cin>>s;
            int c=m[s];
            if(!c)c=1;
            else c++;
            if(c>max){
                max=c;b=s;}
            m[s]=c;
        }
        cout<<b<<endl;
    }
    return 0;
}
