#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int i=1;
    v.push_back(i);
    i=2;
    v.push_back(i);
    for(i=0;i<v.size();i++)cout<<v[i]<<' ';
    cout<<endl;
    return 0;
}
