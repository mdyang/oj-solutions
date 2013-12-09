#include<iostream>
using namespace std;
int main(){
    int temp;
    bool e=false;
    while(cin>>temp){
        if(temp==42)e=true;
        if(e)continue;
        cout<<temp<<endl;
    }
    return 0;
}
