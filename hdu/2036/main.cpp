#include<iostream>
#include<iomanip>
using namespace std;
double area(int x1,int y1,int x2,int y2){
    return double(x1*y2-x2*y1)/2;
}
int coord[200];
int main(){
    int n;
    while(cin>>n&&n>0){
        double s=0;
        for(int i=0;i<2*n;i++)cin>>coord[i];
        for(int i=0;i<n-1;i++)s+=area(coord[i*2],coord[i*2+1],coord[i*2+2],coord[i*2+3]);
        s+=area(coord[2*(n-1)],coord[2*(n-1)+1],coord[0],coord[1]);
        cout<<fixed<<setprecision(1)<<s<<endl;
    }
    return 0;
}
