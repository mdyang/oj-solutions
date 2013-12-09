#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
map<string,string> m;
set<string> s;
void put(const string&a,const string&b){
    m[a]=b;
    m[b]=a;
}
int main(){
    put("A#","Bb");
    put("C#","Db");
    put("D#","Eb");
    put("F#","Gb");
    put("G#","Ab");
    s.insert("Ab minor");
    s.insert("A# major");
    s.insert("A# minor");
    s.insert("C# major");
    s.insert("Db minor");
    s.insert("D# major");
    s.insert("D# minor");
    s.insert("Gb major");
    s.insert("Gb minor");
    s.insert("G# major");
    int c=0;
    string str;
    while(getline(cin,str)){
        string dst=m[str.substr(0,2)];
        if(dst.size()==0){
            cout<<"Case "<<++c<<": UNIQUE\n";
            continue;
        }
        str[0]=dst[0];
        str[1]=dst[1];
        //if(s.find(str)==s.end()){
            cout<<"Case "<<++c<<": "<<str<<endl;
        //    continue;
        //}
        //cout<<"Case "<<++c<<": UNIQUE\n";
    }
    return 0;
}
