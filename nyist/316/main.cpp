#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    string s;
    double price, quantity, sum=0;
    while(cin>>s>>price>>quantity) sum+=(price*quantity);
    cout<<setiosflags(1)<<setprecision(2)<<sum<<endl;
}
