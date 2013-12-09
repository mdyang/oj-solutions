#include <iostream>
#include <string>

using namespace std;

int find(const string& a, const string& b){
    int count = 0;
    const char* ca = a.c_str();
    const char* cb = b.c_str();
    int ia = ca[0]-'0';
    int delta = 1;
    for (int i = 1; i < a.size(); i ++){
        ia *= 2;
        delta *= 2;
        ia += (ca[i]-'0');
    }
    int ib = cb[0] - '0';
    int i = 0, j;
    for (j = 1; j < a.size(); j ++){
        ib *= 2;
        ib += (cb[j]-'0');
    }
    if (ib == ia) count ++;
    for (; j < b.size(); i++, j++){
        if (cb[i] == '1') ib -= delta;
        ib *= 2;
        ib += (cb[j]-'0');
        if (ib == ia) count ++;
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
