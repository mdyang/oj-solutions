#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double sqr(double x){
    return x*x;
}
int main(){
    double x1,y1,x2,y2;
    while(
    cin>>x1>>y1>>x2>>y2){
        cout<<fixed<<setprecision(2)<<sqrt(sqr(x1-x2)+sqr(y1-y2))<<endl;
    }
    return 0;
}
