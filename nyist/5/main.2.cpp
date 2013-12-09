#include <iostream>
#include <string>

using namespace std;

int find(const string& a, const string& b){
    int count = 0;
    int i = 0;
    int pos;
    while ((pos = b.find(a, i)) != string::npos){
        count ++;
        i = pos+1;
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    while (N--){
        string a, b;
        cin>>a>>b;
        cout<<find(a,b)<<endl;
    }
    return 0;
}
