#include<string>
#include<sstream>
#include<iostream>
#include<ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

namespace __gnu_cxx{                                                  
    template<> struct hash< std::string >{                                                
        size_t operator()( const std::string& x ) const{                                              
            return hash< const char* >()( x.c_str() );
        } 
    };
}

int main(){
    string s;
    while(1){
        hash_map<string,int> m;
        getline(cin,s);
        if(!s.compare(string("#")))break;
        stringstream ssin(s);
        string temp;
        int count=0;
        while(ssin>>temp){
            if(m[temp]==0){
                m[temp]=1;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
